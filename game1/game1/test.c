#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//菜单
void menu()
{
	printf("****************************\n");
	printf("****  1.开始    0.结束 *****\n");
	printf("****************************\n");
}

//游戏的算法实现
void game()
{
	int ret = 0;
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{

		//玩家下棋
		PlayerMover(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否胜利
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMover(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否胜利
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
}

//逻辑
void text()
{
	int input = 0;
	srand((unsigned int)time(NULL));//时间戳
	do
	{

		menu();
		printf("请输入：>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			printf("进入三子棋游戏\n");
			game();//游戏模块
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}

//主函数
int main()
{
	text();
	return 0;
}
