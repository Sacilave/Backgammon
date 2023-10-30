#define BoardLimit 30

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

char startTitle[] = "��ʼ��Ϸ";

int refreshBorad(int *board, int row, int column) {
	printf("\n------\n����\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++) { printf("----"); }
		printf("-"); printf("\n");
		for (int j = 0; j < column; j++) { printf("| %c ", *(board + i * column * i + j)); }  // ȡֵ
		printf("|"); printf("\n");
	}
	for (int j = 0; j < column; j++)
	{
		printf("----");
	}
	printf("-");
}

int initBoard() {
	system("cls");
	int row = 3, column = 3; char board[BoardLimit][BoardLimit];
	for (int i = 0; i < BoardLimit; i++) { for (int j = 0; j < BoardLimit; j++) { board[i][j] = ' '; } }  // ��ʼ��ֵΪ ' '
	printf("�������̵ĳ��Ϳ�\n");
	scanf("%d %d", &row, &column);
	if (row > BoardLimit || column > BoardLimit) 
	{ 
		printf("���Ϳ�ӦС��%d\n", BoardLimit); 
		Sleep(1000);
		initBoard();
	}
	else for (int i = 0; i < row; i++) { for (int j = 0; j < column; j++) { board[i][j] = ' '; } }
	refreshBorad(board, row, column);
}

int title() {  // ������棬����� layout()
	while (1)
	{
		printf("\n------------ ������ -------------\n1.%s\t\t2.�˳�\n", &startTitle);
		char input = getchar();
		system("cls");
		if (input == '1') { initBoard(); break; }
		else if (input == '2') { printf("�˳���...\n"); exit(0); break; }
		else { printf("������󣡲�������ѡ�����\n"); continue; }
	}
}

int main22() {
	initBoard();
}