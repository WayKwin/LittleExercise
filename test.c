#include "game.h"
char board[ROW][COL] = { 0 };

void game(){
	InitBoard(board, 3, 3);
	PrintBoard(board, 3, 3);
	while (1)
	{
	if (1 == CheckFull(board))  // 玩家先下棋 平局肯定是玩家先下满
	{
		PrintBoard(board, 3, 3);
		printf("棋盘满了\n");
		break;
	}
	PlayerMove(board);
	if (0 == CheckWin(board))
	{
		PrintBoard(board, 3, 3);
		printf("我赢了\n");
		break;
	}
	CompterMove(board);
	PrintBoard(board, 3, 3);
	if (0 == CheckWin(board))
	{
		PrintBoard(board, 3, 3);
		printf("电脑赢了\n");
		break;
	}
}
}
void menu(){
	printf("****************\n");
	printf("***1.开始 0.退出****\n");
	int choose = 0;
		printf("请输出选择\n");

	do{
			scanf("%d", &choose);
			switch(choose)
			{
			case 1:
					game();
					break;
			case 0:
					break;
				default :
					printf("请重新输入\n");
					continue;
			}

	}
	while (choose);
}
int main()
{
	//srand((unsigned int)time(NULL));
	menu();
	system("pause");
	return 0;
}