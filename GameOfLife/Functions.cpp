#include "Header.h"
#include "Function.h"

std::vector<std::vector<int>> Randomize(std::vector<std::vector<int>> state, int width, int height)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double>dist(0, 1.0);
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int oneOrZero = Probability_Function(dist(mt));
			state[i][j] = oneOrZero;
		}
	}
	return state;
}

std::vector<std::vector<char>>Render_Board(std::vector<std::vector<int>>board_state, int width, int height)
{
	std::vector<std::vector<char>>char_state(width, std::vector<char>(height, ' '));
	std::vector<std::vector<char>>rendered_board = Render(board_state, char_state, width, height);
	return rendered_board;
}

void Print_Board(std::vector<std::vector<char>>board_state, int width, int height)
{
	for(int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::cout << board_state[x][y] << ' ';
		}
		std::cout << '\n';
	}
}

std::vector<std::vector<char>>Render(std::vector<std::vector<int>>int_state, std::vector<std::vector<char>>char_state, int width, int height)
{
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			if (int_state[i][j] == ALIVE) {
				char_state[i][j] = LIVECELL;
			}
			else char_state[i][j] = DEADCELL;
		}
	}
	return char_state;
}

int Probability_Function(double x)
{
	if (x >= .50) {
		return 1;
	}
	else { return 0; }
}