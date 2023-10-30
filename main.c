#define BoardLimit 30

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

char startTitle[] = "开始游戏";

int refreshBorad(int *board, int row, int column) {
	printf("\n------\n棋盘\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++) { printf("----"); }
		printf("-"); printf("\n");
		for (int j = 0; j < column; j++) { printf("| %c ", *(board + i * column * i + j)); }  // 取值
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
	for (int i = 0; i < BoardLimit; i++) { for (int j = 0; j < BoardLimit; j++) { board[i][j] = ' '; } }  // 初始赋值为 ' '
	printf("输入棋盘的长和宽\n");
	scanf("%d %d", &row, &column);
	if (row > BoardLimit || column > BoardLimit) 
	{ 
		printf("长和宽都应小于%d\n", BoardLimit); 
		Sleep(1000);
		initBoard();
	}
	else for (int i = 0; i < row; i++) { for (int j = 0; j < column; j++) { board[i][j] = ' '; } }
	refreshBorad(board, row, column);
}

int title() {  // 标题界面，会调用 layout()
	while (1)
	{
		printf("\n------------ 五子棋 -------------\n1.%s\t\t2.退出\n", &startTitle);
		char input = getchar();
		system("cls");
		if (input == '1') { initBoard(); break; }
		else if (input == '2') { printf("退出中...\n"); exit(0); break; }
		else { printf("输入错误！不就两个选项嘛？！\n"); continue; }
	}
}

int main22() {
	initBoard();
}