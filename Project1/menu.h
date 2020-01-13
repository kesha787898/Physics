#pragma once
#include"func.h"
#include"zakoni.h"
int code;
void newMenu();
int num;
void Bigmenu() {
	newMenu();
}
void info() {
	while (true) {
		system("cls");
		HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cd;
		cd.X = 70;
		cd.Y = 15;
		SetConsoleCursorPosition(hd, cd);
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_GREEN);
		cout << "Работу выполнил студент группы ФИТ-171 Гончаренко Александр\n";
		//printf_s();
		SetConsoleTextAttribute(hConsoleHandle, x);
		printf_s("1.Вернуться");
		int numm = 0;
		numm = _getch();
		if (numm == 13)break;
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
	}
}
void zanul(bool arr[4]) { { for (int i = 0; i < 4; i++) { arr[i] = 0; } };
if (num == -1) { num = 3; };
if (num == 4) { num = 0; };
arr[num] = 1;
}
void newMenu() {
	num = 0;
SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
	bool numString[4] = { 1,0,0,0};
	setlocale(LC_ALL, "Russian");
	SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY); system("cls");
	while (true) {
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		system("cls");
		if (numString[0] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("1.Demonstracia\n");
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		if (numString[1] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("2.Baza dannih\n");
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		if (numString[2] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("3.About Me\n");
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		if (numString[3] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("4.Exit\n");
		code = _getch();
		switch (code) {
		case 72:num--;
			break;  //up
		case 80:num++;
			break;//down
		case 13: {switch (num) {
		case 3: exit(0); break;
		case 2:info(); break;
		case 1: base(); break;
		case 0: physics(); break;
		}
		}
			 break;//ENTER
		};
		zanul(numString);
	};
};
