#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

char startTitle[] = "��ʼ��Ϸ";

int layout() {
	const int row = 3, column = 3; 
	printf("�������̵ĳ��Ϳ�\n");
	scanf("%d %d", &row, &column);


	// ������̬��ά����
	char** board = (char**)malloc(sizeof(char*) * row);
	for (int i = 0; i < row; i++) {
		*(board + i) = (char*)malloc(sizeof(char) * column);
	}
	// ���������¸�ֵΪ��ֵ
	for (int i = 0; i < column; i++) {
		free(*(board + i));
		board[i] = ' ';
	}

	// ˢ������
	printf("\n----\n����\n");
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

�ͷŶ�̬��ά�����ڴ�
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
		printf("\n------------ ������ -------------\n1.%s\t\t2.�˳�\n", &startTitle);
		system("cls");
		if (input == '1') { layout(); break; }
		else if (input == '2') { printf("�˳���...\n"); exit(0); break; }
		else { printf("������󣡲�������ѡ�����\n"); continue; }
	}
}

int main() {
	layout();
}