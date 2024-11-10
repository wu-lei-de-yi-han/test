#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//�˵�
void menu()
{
	printf("****************************\n");
	printf("****  1.��ʼ    0.���� *****\n");
	printf("****************************\n");
}

//��Ϸ���㷨ʵ��
void game()
{
	int ret = 0;
	//����-����߳���������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{

		//�������
		PlayerMover(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�ʤ��
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMover(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�ʤ��
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

//�߼�
void text()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ʱ���
	do
	{

		menu();
		printf("�����룺>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			printf("������������Ϸ\n");
			game();//��Ϸģ��
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}

//������
int main()
{
	text();
	return 0;
}
