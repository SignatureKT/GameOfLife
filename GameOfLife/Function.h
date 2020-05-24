#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

std::vector<std::vector<int>> Randomize(std::vector<std::vector<int>>  state, int width, int height);
int Probability_Function(double x);
std::vector<std::vector<char>> Render_Board(std::vector<std::vector<int>>board_state, int width, int height);
void Print_Board(std::vector<std::vector<char>>board_state, int width, int height);
std::vector<std::vector<char>>Render(std::vector<std::vector<int>>int_state, std::vector<std::vector<char>> char_state, int width, int height);

#endif