#include "Header.h"
#include "Function.h"
#include "Check-Functions.h"

std::vector<std::vector<char>>Next_Board(std::vector<std::vector<char>>board_state, int width, int height);

void Get_Size(int& board_width, int& board_height);

void GameOfLife(std::vector<std::vector<char>>& board_state, int board_width, int board_height);

int main(int argc, char* argv[])
{
	int board_width, board_height;
	Get_Size(board_width, board_height);
	std::vector<std::vector<int>>dead_state(board_width, std::vector<int>(board_height, 0)); // creates the board
	std::vector<std::vector<int>>random_state = Randomize(dead_state, board_width, board_height); // randomizes the board
	std::vector<std::vector<char>>board_state = Render_Board(random_state, board_width, board_height); // changes int board to char
	Print_Board(board_state, board_width, board_height); // prints init board
	bool update = true;
	while (update) { // loop
		GameOfLife(board_state, board_width, board_height);
	}
	return 0;
}

void GameOfLife(std::vector<std::vector<char>>& board_state, int board_width, int board_height)
{
	std::vector<std::vector<char>>next_board_state = Next_Board(board_state, board_width, board_height);
	std::cout << '\n';
	system("cls");
	Print_Board(next_board_state, board_width, board_height);
	board_state = next_board_state;
}

void Get_Size(int& board_width, int& board_height)
{
	std::cout << "Board Width: ";
	std::cin >> board_width;
	std::cout << "Board Height: ";
	std::cin >> board_height;
}

std::vector<std::vector<char>>Next_Board(std::vector<std::vector<char>>board_state, int width, int height)
{
	std::vector<std::vector<char>>new_state = board_state;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int numOfNeighbor = 0;
			numOfNeighbor = Check_Neighbor(board_state, x, y, width, height);
			if (board_state[x][y] == LIVECELL) {
				if (numOfNeighbor < 2) {
					new_state[x][y] = DEADCELL;
				}
				else if (numOfNeighbor == 2 || numOfNeighbor == 3) {
					new_state[x][y] = LIVECELL;
				}
				else if (numOfNeighbor > 3) {
					new_state[x][y] = DEADCELL;
				}
			}
			if (board_state[x][y] == DEADCELL &&  numOfNeighbor == 3) {
				new_state[x][y] = LIVECELL;
			}
		}
	}
	return new_state;
}

