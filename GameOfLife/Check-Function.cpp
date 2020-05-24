#include "Header.h"
#include "Check-Functions.h"

int Check_Neighbor(std::vector<std::vector<char>>board_state, int x, int y, int width, int height) {
	int num = 0;
	int xEndOfArray = width - 1;
	int yEndOfArray = height - 1;
	if (x == 0 || x == xEndOfArray || y == 0 || y == yEndOfArray) {
		if (x == 0 && y == 0) {
			Check_Right(board_state, x, y);
			Check_Down_Right(board_state, x, y);
			Check_Down(board_state, x, y);
		}
		else if (x == 0 && y == yEndOfArray) {
			Check_Up(board_state, x, y);
			Check_Up_Right(board_state, x, y);
			Check_Right(board_state, x, y);
		}
		else if (x == xEndOfArray && y == 0) {
			Check_Down(board_state, x, y);
			Check_Down_Left(board_state, x, y);
			Check_Left(board_state, x, y);
		}
		else if (x == xEndOfArray && y == yEndOfArray) {
			Check_Left(board_state, x, y);
			Check_Up_Left(board_state, x, y);
			Check_Up(board_state, x, y);
		}
		else if (y == 0 && x != 0 && x != xEndOfArray) {
			Check_Right(board_state, x, y);
			Check_Down_Right(board_state, x, y);
			Check_Down(board_state, x, y);
			Check_Down_Left(board_state, x, y);
			Check_Left(board_state, x, y);
		}
		else if (x == xEndOfArray && y != 0 && y != yEndOfArray) {
			Check_Up(board_state, x, y);
			Check_Down(board_state, x, y);
			Check_Down_Left(board_state, x, y);
			Check_Left(board_state, x, y);
			Check_Up_Left(board_state, x, y);
		}
		else if (y == yEndOfArray && x != 0 && x != xEndOfArray) {
			Check_Up(board_state, x, y);
			Check_Up_Right(board_state, x, y);
			Check_Right(board_state, x, y);
			Check_Left(board_state, x, y);
			Check_Up_Left(board_state, x, y);
		}
		else if (x == 0 && y != 0 && y != yEndOfArray) {
			Check_Up(board_state, x, y);
			Check_Up_Right(board_state, x, y);
			Check_Right(board_state, x, y);
			Check_Down_Right(board_state, x, y);
			Check_Down(board_state, x, y);
		}
		else {
			std::cout << "Check Neighbor ERROR!!!";
			exit(1);
		}
		return num;
	}
	else {
		num += Check_Up(board_state, x, y)
			+ Check_Up_Right(board_state, x, y)
			+ Check_Right(board_state, x, y)
			+ Check_Down_Right(board_state, x, y)
			+ Check_Down(board_state, x, y)
			+ Check_Down_Left(board_state, x, y)
			+ Check_Left(board_state, x, y)
			+ Check_Up_Left(board_state, x, y);
	}
	return num;
}

int Check_Up(std::vector<std::vector<char>>board_state, int x, int y)
{
	if (board_state[x][y - 1] == LIVECELL) {
		return 1;
	}
	else return 0;
}

int Check_Up_Right(std::vector<std::vector<char>>board_state, int x, int y)
{
	if (board_state[x + 1][y - 1] == LIVECELL) {
		return 1;
	}
	else return 0;
}

int Check_Right(std::vector<std::vector<char>>board_state, int x, int y)
{
	if (board_state[x + 1][y] == LIVECELL) {
		return 1;
	}
	else return 0;
}

int Check_Down_Right(std::vector<std::vector<char>>board_state, int x, int y)
{
	if (board_state[x + 1][y + 1] == LIVECELL) {
		return 1;
	}
	else return 0;
}

int Check_Down(std::vector<std::vector<char>>board_state, int x, int y)
{
	if (board_state[x][y + 1] == LIVECELL) {
		return 1;
	}
	else return 0;
}

int Check_Down_Left(std::vector<std::vector<char>>board_state, int x, int y)
{
	if (board_state[x - 1][y + 1] == LIVECELL) {
		return 1;
	}
	else return 0;
}

int Check_Left(std::vector<std::vector<char>>board_state, int x, int y)
{
	if (board_state[x - 1][y] == LIVECELL) {
		return 1;
	}
	else return 0;
}

int Check_Up_Left(std::vector<std::vector<char>>board_state, int x, int y)
{
	if (board_state[x - 1][y - 1] == LIVECELL) {
		return 1;
	}
	else return 0;
}