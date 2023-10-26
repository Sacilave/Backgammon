#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

char startTitle[] = "开始游戏";

int layout() {
	const int row = 3, column = 3; 
	printf("输入棋盘的长和宽\n");
	scanf("%d %d", &row, &column);


	// 创建动态二维数组
	char** board = (char**)malloc(sizeof(char*) * row);
	for (int i = 0; i < row; i++) {
		*(board + i) = (char*)malloc(sizeof(char) * column);
	}
	// 将数组重新赋值为空值
	for (int i = 0; i < column; i++) {
		free(*(board + i));
		board[i] = ' ';
	}

	// 刷新棋盘
	printf("\n----\n棋盘\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("----");
		}
		printf("-");
		printf("\n");
		for (int j = 0; j < column; j++)
		{
			printf("| %c ", board[i, j]);
		}
		printf("|");
		printf("\n");
		
	}
	for (int j = 0; j < column; j++)
	{
		printf("----");
	}
	printf("-");
}

/*
for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			board[i][j] = ' ';
		}
	}

释放动态二维数组内存
for (i = 0; i < m; i++) {
	free(*(aa + i));
	aa[i] = NULL;
}
free(aa);
aa = NULL;
*/

int title() {
	while (1)
	{
		char input = getchar();
		printf("\n------------ 五子棋 -------------\n1.%s\t\t2.退出\n", &startTitle);
		system("cls");
		if (input == '1') { layout(); break; }
		else if (input == '2') { printf("退出中...\n"); exit(0); break; }
		else { printf("输入错误！不就两个选项嘛？！\n"); continue; }
	}
}

int main() {
	layout();
}