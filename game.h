#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
char board[ROW][COL];

void InitBoard(char board[ROW][COL], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL]);
void CompterMove(char board[ROW][COL]);
int CheckWin(char board[ROW][COL]);
int CheckFull(char board[ROW][COL]);



