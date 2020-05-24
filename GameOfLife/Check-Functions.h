#pragma once
#ifndef Check_Functions_H_INCLUDED
#define Check_Functions_H_INCLUDED

int Check_Neighbor(std::vector<std::vector<char>>board_state, int x, int y, int width, int height);
int Check_Up(std::vector<std::vector<char>>board_state, int x, int y);
int Check_Up_Right(std::vector<std::vector<char>>board_state, int x, int y);
int Check_Right(std::vector<std::vector<char>>board_state, int x, int y);
int Check_Down_Right(std::vector<std::vector<char>>board_state, int x, int y);
int Check_Down(std::vector<std::vector<char>>board_state, int x, int y);
int Check_Down_Left(std::vector<std::vector<char>>board_state, int x, int y);
int Check_Left(std::vector<std::vector<char>>board_state, int x, int y);
int Check_Up_Left(std::vector<std::vector<char>>board_state, int x, int y);

#endif