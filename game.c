#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, 32, row*col);
	
}
int CheckFull(char board[ROW][COL])
{
	int i = 0,j=0;
	for (i = 0; i < ROW; i++)
	{
		for (j=0; j < COL; j++)
		{
			if (32 == board[i][j])
			{	
				return 0;
			}
		}
	
	}
	return 1;
}
int CheckWin(char board[ROW][COL])
{

	for (int i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!=' ')
			return 0;
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return 0;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return 0;
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return 0;
	 else if (1==CheckFull(board))
		return 2;
	else
		return 1;
	

}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);

		if (i < 2)
			printf("---|---|---\n");
	}


}
void PlayerMove(char board[ROW][COL])
{
	int x=0, y=0;
		printf("请输入坐标\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		if ((x >= 0) && (x <= 2) && (y >= 0) && (y <= 2))
		{	
		if (' ' == board[x][y])
		{
			board[x][y] = 'X';
			break;
		}
		else
		{
			printf("输入坐标已占\n");
		}
		}
		else
		{
			printf("您输入坐标有误\n");
		}
	}
	
}
void CompterMove(char board[ROW][COL])
{

	while (1)
	{
		
		int x = rand() % 3;
		int y = rand() % 3;
		if (' ' == board[x][y])
		{
			board[x][y] = 'O';
			break;
		}
	}
}
