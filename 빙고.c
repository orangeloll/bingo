#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //system ����� ���� ���
#include <stdlib.h> //rand()�Լ� ����� ���� ���
#include <time.h>  //seed�� �ٲٱ� ���� �θ��� ���

void textcolor(int color_number);
void Exp(int o);
int lps(int my, int com);
int getmenu(int o);
void CursorView();
void gotoxy(int x, int y);
int input_number(int mc);
void erase();
void winner(int win);
int checkbig(int bingo[5][5]);

//���� ����
int check[50];
int count = 0;

int main() {
	system("mode con:cols=120 lines=40");//�ܼ� ������ ����
	system("color 3");//�ؽ�Ʈ ������
	system("title ����");////�ܼ� ����
	int mystr[5][5] = { 0, };//����� ������
	int comstr[5][5] = { 0, };//��ǻ�� ������
	int Bingo[5][5] = { 0, };//������ �������� �迭
	int a, b, c, start, num = 1, my, com, lpswin, mycheck, comcheck, number,end;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 120; i++) {
		printf("#");
	}
	for (int i = 0; i < 39; i++) {
		printf("\n");
	}
	for (int i = 0; i < 120; i++) {
		printf("#");
	}
	gotoxy(40, 15); printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(39, 16); printf("| -------------------------------------- |");
	for (int j = 39; j < 40; j++) {
		for (int k = 17; k < 20; k++) {
			gotoxy(j, k); printf("| |                                    | |");
		}
	}
	gotoxy(39, 20); printf("| |             ���� ����              | |");
	for (int j = 39; j < 40; j++) {
		for (int k = 21; k < 25; k++) {
			gotoxy(j, k); printf("| |                                    | |");
		}
	}
	gotoxy(39, 25); printf("| -------------------------------------- |");
	gotoxy(40, 26); printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(56, 27); printf("|      |");
	gotoxy(40, 28); printf("�ѤѤѤѤѤѤ�            �ѤѤѤѤѤѤ�");
	gotoxy(39, 29); printf("|                                        |");
	gotoxy(40, 30); printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(45, 34); printf("->Enter�� �����ø� �Ѿ�ϴ�.");
	getchar();
	if (getchar) {
		system("cls");
	}
	CursorView();
	while (1) {
		gotoxy(55, 15); printf("���ӽ���(0)");
		gotoxy(55, 18); printf("���Ӽ���(1)");
		gotoxy(55, 21); printf("  ����(2)");
		gotoxy(40, 25);
		printf("���Ͻô� �޴� ���� ��ȣ�� �Է� �� ���͸� �����ּ���.");
		scanf("%d", &a);
		getchar();
		system("cls");
		if (a == 1) {
			Exp(a);
			system("cls");
			continue;
		}
		else getmenu(a); break;
	}//���θ޴� �Է�
	//start = getmenu(a);
	if (getmenu(a)==3) {
		textcolor(6);
		while (1) {
			com = rand() % 3 + 1;//���������� �� �ϳ� �ο�
			printf("����ڿ� ��ǻ�Ͱ� ������������ �մϴ�\n");
			printf("�̱� ���� �����Դϴ�.");
			printf("������ 1�� �Է��Ͻð� ������ 2�� ���� 3�� �Է��Ͻø� �˴ϴ�.");
			scanf("%d", &my);
			lpswin = lps(my, com);
			printf("%d %d\n", my, com);
			if (lpswin == 6) {
				printf("������ ��ǻ���Դϴ�.");
				break;
			}
			else if (lpswin == 7) {
				printf("���º��Դϴ�. �ٽ� ���ּ���.");
				continue;
			}
			else if (lpswin == 8) {
				printf("������ ������Դϴ�.");
				break;
			}
		}
		system("cls");
		if (lpswin == 8) {
			while (1) {
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						Bingo[i][j] = num;
						num++;
					}
				}
				for (int i = 0; i < 100; i++)//����
				{
					int rand1 = rand() % 5;
					int rand2 = rand() % 5;
					int rand3 = rand() % 5;
					int rand4 = rand() % 5;
					int temp;
					temp = Bingo[rand1][rand2];
					Bingo[rand1][rand2] = Bingo[rand3][rand4];
					Bingo[rand3][rand4] = temp;
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						mystr[i][j] = Bingo[i][j];
				}
				for (int i = 0; i < 100; i++)//����
				{
					int rand1 = rand() % 5;
					int rand2 = rand() % 5;
					int rand3 = rand() % 5;
					int rand4 = rand() % 5;
					int temp;
					temp = Bingo[rand1][rand2];
					Bingo[rand1][rand2] = Bingo[rand3][rand4];
					Bingo[rand3][rand4] = temp;
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						comstr[i][j] = Bingo[i][j];
				}
				while (1) {
					printf("#########################\n");
					printf("#         Player        #\n");
					printf("#########################\n");
					printf(" --------------------\n");
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 5; j++)
							printf("%4d", mystr[i][j]);
						printf("\n");
					}
					printf(" ____________________\n");
					printf("\n");
					number = input_number(0);
					erase(mystr, number);
					erase(comstr, number);
					number = input_number(1);
					erase(mystr, number);
					erase(comstr, number);
					mycheck = checkbig(mystr);
					comcheck = checkbig(comstr);
					Sleep(1000);
					system("cls");
					if (mycheck == 1 || comcheck == 1) break;
				}
				printf("#########################\n");
				printf("#         Player        #\n");
				printf("#########################\n");
				printf(" --------------------\n");
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						printf("%4d", mystr[i][j]);
					printf("\n");
				}
				printf("#########################\n");
				printf("#        computer       #\n");
				printf("#########################\n");
				printf(" --------------------\n");
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						printf("%4d", comstr[i][j]);
					printf("\n");
				}

				if (mycheck != 0) winner(1);
				else if(comcheck!=0) winner(2);
				printf("�� �Ͻ÷��� 1�� �׸��Ͻ÷��� 2�� �����ּ���.\n");
				scanf("%d", &end);
				num = 1;
				for (int i = 0; i < 50; i++) {
					check[i] = 0;
				}
				system("cls");
				if (end == 1) continue;
				else if (end == 2) exit(0);
			}
		}
		if (lpswin == 6) {
			while(1) {
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						Bingo[i][j] = num;
						num++;
					}
				}
				for (int i = 0; i < 100; i++)//����
				{
					int rand1 = rand() % 5;
					int rand2 = rand() % 5;
					int rand3 = rand() % 5;
					int rand4 = rand() % 5;
					int temp;
					temp = Bingo[rand1][rand2];
					Bingo[rand1][rand2] = Bingo[rand3][rand4];
					Bingo[rand3][rand4] = temp;
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						mystr[i][j] = Bingo[i][j];
				}
				for (int i = 0; i < 100; i++)//����
				{
					int rand1 = rand() % 5;
					int rand2 = rand() % 5;
					int rand3 = rand() % 5;
					int rand4 = rand() % 5;
					int temp;
					temp = Bingo[rand1][rand2];
					Bingo[rand1][rand2] = Bingo[rand3][rand4];
					Bingo[rand3][rand4] = temp;
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						comstr[i][j] = Bingo[i][j];
				}
				while (1) {
					printf("#########################\n");
					printf("#         Player        #\n");
					printf("#########################\n");
					printf(" --------------------\n");
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 5; j++)
							printf("%4d", mystr[i][j]);
						printf("\n");
					}
					printf(" ____________________\n");
					printf("\n");
					number = input_number(1);
					erase(mystr, number);
					erase(comstr, number);
					number = input_number(0);
					erase(mystr, number);
					erase(comstr, number);

					mycheck = checkbig(mystr);
					comcheck = checkbig(comstr);
					Sleep(1000);
					system("cls");
					if (mycheck == 1 || comcheck == 1) break;
				}
				printf("#########################\n");
				printf("#         Player        #\n");
				printf("#########################\n");
				printf(" --------------------\n");
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						printf("%4d", mystr[i][j]);
					printf("\n");
				}
				printf("#########################\n");
				printf("#        computer       #\n");
				printf("#########################\n");
				printf(" --------------------\n");
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						printf("%4d", comstr[i][j]);
					printf("\n");
				}

				if (mycheck != 0 && comcheck == 0) winner(1);
				else if (comcheck != 0 && mycheck == 0) winner(2);
				else winner(3);
				printf("�� �Ͻ÷��� 1�� �׸��Ͻ÷��� 2�� �����ּ���.\n");
				num = 1;
				for (int i = 0; i < 50; i++) {
					check[i] = 0;
				}
				scanf("%d", &end);
				system("cls");
				if (end == 1) continue;
				else if (end == 2) exit(0);
			}
		}
	}
}


void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}//�ܼ�â �ؽ�Ʈ �� ����

void Exp(int o) {
	int e = o;
	gotoxy(48, 10); printf("*****���� ����*****");
	gotoxy(35, 13); printf("*5�� 5���� ��������1~25 ���ڷ� �ߺ����� ä��ϴ�.");
	gotoxy(33, 15); printf("*�� �Ǵ� ��, �밢������ 5���� ���ڸ� ����� 1�� �ϼ�");
	gotoxy(42, 17); printf("*5���� ���� �ϼ��� ���� �¸��մϴ�.");
	gotoxy(40, 20); printf(">�޴��� ���ư��÷��� Enter�� �����ּ���.");
	getchar();
}//���� ������ �����ִ� �Լ�

int lps(int my, int com) {
	if ((my == 1 && com == 2) || (my == 2 && com == 3) || (my == 3 && com == 1)) {
		return 6;
	}
	else if ((my == 1 && com == 1) || (my == 2 && com == 2) || (my == 3 && com == 3)) {
		return 7;
	}
	else if ((my == 2 && com == 1) || (my == 3 && com == 2) || (my == 1 && com == 3)) {
		return 8;
	}
}//lock paper scissors�� ���Ӹ�


int getmenu(int o) {
	if (o == 0) {
		return 3;
	}
	else if (o == 2) {
		exit(0);
	}
}//�Է¹��� �޴�

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}//���콺 Ŀ�� �����

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//Ư�� ��ǥ�� �̵��ϱ����� �Լ�

int input_number(int mc) {
	int num;
	int x, re;
		do {
			re = 0;
			if (mc == 0) {
				printf("1~25 ������ ���ڸ� �Է��ϼ��� : ");
				scanf("%d", &num);
				if (num < 1 || num>25) {
					re = 1;
				}
			}
			else {
				num = rand() % 25 + 1;
			}
			if (re == 0) {
				for (x = 0; x < count; x++) {
					if (check[x] == num) {
						re = 1;
						break;
					}
				}
			}
		} while (re == 1);
	check[count++] = num;
	if (mc == 0) {
		printf("����ڰ� %d�� �����߽��ϴ�.\n", num);
	}
	else printf("��ǻ�Ͱ� %d�� �����߽��ϴ�.\n\n",num);
	return num;
}//���� ���� ����

int checkbig(int bingo[5][5]) {
	int x, y, sum,all=0;
	
	for (y = 0;y < 5; y++) {
		sum = 0;
		for (x = 0; x < 5; x++) {
			sum +=bingo[y][x];
			
		}
		if (sum == 0) {
			all++;
		}	
	}
	
	for (x = 0; x < 5; x++) {
		sum = 0;
		for (y = 0; y < 5; y++) {
			sum += bingo[y][x];
		}
		if (sum == 0) {
			all++;
		}
	}
	sum = 0;
	for (x = 0; x < 5; x++) {
		sum += bingo[x][x];
	}
	if (sum == 0) {
		all++;
	}
	sum = 0;
	for (x = 0; x < 5; x++) {
		sum += bingo[x][5 - x - 1];
	}
	if (sum == 0) {
		all++;
	}
	if (all > 4) return 1;
	return 0;
}//���� ��

void winner(int win) {
	if (win == 1) {
		printf("����ڰ� �̰���ϴ�.\n");
	}
	else if(win==2) {
		printf("��ǻ�Ͱ� �̰���ϴ�.\n");
	}
	else {
		printf("���º��Դϴ�.\n");
	}
}//����

void erase(int bingo[5][5], int number) {
	int x, y;
	for (y = 0; y < 5; y++) {
		for (x = 0; x < 5; x++) {
			if (bingo[y][x] == number) {
				bingo[y][x] = 0;
			}
		}
	}
}//�Էµ� ���� �κ� 0���� �ٲٱ�