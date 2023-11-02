#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //system 사용을 위한 헤더
#include <stdlib.h> //rand()함수 사용을 위한 헤더
#include <time.h>  //seed값 바꾸기 위해 부르는 헤더

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

//전역 변수
int check[50];
int count = 0;

int main() {
	system("mode con:cols=120 lines=40");//콘솔 사이즈 설정
	system("color 3");//텍스트 색지정
	system("title 빙고");////콘솔 제목
	int mystr[5][5] = { 0, };//사용자 빙고판
	int comstr[5][5] = { 0, };//컴퓨터 빙고판
	int Bingo[5][5] = { 0, };//빙고판 섞기위한 배열
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
	gotoxy(40, 15); printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	gotoxy(39, 16); printf("| -------------------------------------- |");
	for (int j = 39; j < 40; j++) {
		for (int k = 17; k < 20; k++) {
			gotoxy(j, k); printf("| |                                    | |");
		}
	}
	gotoxy(39, 20); printf("| |             빙고 게임              | |");
	for (int j = 39; j < 40; j++) {
		for (int k = 21; k < 25; k++) {
			gotoxy(j, k); printf("| |                                    | |");
		}
	}
	gotoxy(39, 25); printf("| -------------------------------------- |");
	gotoxy(40, 26); printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	gotoxy(56, 27); printf("|      |");
	gotoxy(40, 28); printf("ㅡㅡㅡㅡㅡㅡㅡ            ㅡㅡㅡㅡㅡㅡㅡ");
	gotoxy(39, 29); printf("|                                        |");
	gotoxy(40, 30); printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
	gotoxy(45, 34); printf("->Enter를 누르시면 넘어갑니다.");
	getchar();
	if (getchar) {
		system("cls");
	}
	CursorView();
	while (1) {
		gotoxy(55, 15); printf("게임시작(0)");
		gotoxy(55, 18); printf("게임설명(1)");
		gotoxy(55, 21); printf("  종료(2)");
		gotoxy(40, 25);
		printf("원하시는 메뉴 뒤의 번호를 입력 후 엔터를 눌러주세요.");
		scanf("%d", &a);
		getchar();
		system("cls");
		if (a == 1) {
			Exp(a);
			system("cls");
			continue;
		}
		else getmenu(a); break;
	}//메인메뉴 입력
	//start = getmenu(a);
	if (getmenu(a)==3) {
		textcolor(6);
		while (1) {
			com = rand() % 3 + 1;//가위바위보 중 하나 부여
			printf("사용자와 컴퓨터가 가위바위보를 합니다\n");
			printf("이긴 쪽이 선공입니다.");
			printf("가위는 1를 입력하시고 바위는 2을 보는 3을 입력하시면 됩니다.");
			scanf("%d", &my);
			lpswin = lps(my, com);
			printf("%d %d\n", my, com);
			if (lpswin == 6) {
				printf("선공은 컴퓨터입니다.");
				break;
			}
			else if (lpswin == 7) {
				printf("무승부입니다. 다시 해주세요.");
				continue;
			}
			else if (lpswin == 8) {
				printf("선공은 사용자입니다.");
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
				for (int i = 0; i < 100; i++)//섞기
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
				for (int i = 0; i < 100; i++)//섞기
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
				printf("더 하시려면 1을 그만하시려면 2를 눌러주세요.\n");
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
				for (int i = 0; i < 100; i++)//섞기
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
				for (int i = 0; i < 100; i++)//섞기
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
				printf("더 하시려면 1을 그만하시려면 2를 눌러주세요.\n");
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
}//콘솔창 텍스트 색 변경

void Exp(int o) {
	int e = o;
	gotoxy(48, 10); printf("*****게임 설명*****");
	gotoxy(35, 13); printf("*5행 5열의 숫자판을1~25 숫자로 중복없이 채웁니다.");
	gotoxy(33, 15); printf("*행 또는 열, 대각선으로 5개의 숫자를 지우면 1개 완성");
	gotoxy(42, 17); printf("*5개가 먼저 완성된 쪽이 승리합니다.");
	gotoxy(40, 20); printf(">메뉴로 돌아가시려면 Enter를 눌러주세요.");
	getchar();
}//게임 설명을 보여주는 함수

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
}//lock paper scissors의 줄임말


int getmenu(int o) {
	if (o == 0) {
		return 3;
	}
	else if (o == 2) {
		exit(0);
	}
}//입력받은 메뉴

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}//마우스 커서 숨기기

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//특정 좌표로 이동하기위한 함수

int input_number(int mc) {
	int num;
	int x, re;
		do {
			re = 0;
			if (mc == 0) {
				printf("1~25 사이의 숫자를 입력하세요 : ");
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
		printf("사용자가 %d를 선택했습니다.\n", num);
	}
	else printf("컴퓨터가 %d를 선택했습니다.\n\n",num);
	return num;
}//지울 숫자 선택

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
}//빙고 줄

void winner(int win) {
	if (win == 1) {
		printf("사용자가 이겼습니다.\n");
	}
	else if(win==2) {
		printf("컴퓨터가 이겼습니다.\n");
	}
	else {
		printf("무승부입니다.\n");
	}
}//승자

void erase(int bingo[5][5], int number) {
	int x, y;
	for (y = 0; y < 5; y++) {
		for (x = 0; x < 5; x++) {
			if (bingo[y][x] == number) {
				bingo[y][x] = 0;
			}
		}
	}
}//입력된 숫자 부분 0으로 바꾸기