#pragma once
#include<string>
#include<string.h>
#include<fstream>
#include<vector>
#include<locale.h>
#include<Windows.h>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
HWND hwn = GetConsoleWindow();
COORD coord;
HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
WORD x = BACKGROUND_RED;
ifstream filein;
ofstream fileout;
int nnum;
void zanul6(bool arr[6]) { { for (int i = 0; i < 6; i++) { arr[i] = 0; } };
if (nnum == -1) { nnum = 5; };
if (nnum == 6) { nnum = 0; };
arr[nnum] = 1;
}
class poet {
public:
	string name;
	string surname;
	string Bdate;
	string Ddate;
	string proizvedenie;
public:void print() {
	
	cout << "|  ";
	cout.fill(' ');
	cout.width(12);
		cout << name;
		cout << "|";
		cout.fill(' ');
		cout.width(15);
		cout << surname;
		cout << "|";
		cout.fill(' ');
		cout.width(15);
		cout << Bdate;
		cout << "|";
		cout.fill(' ');
		cout.width(15);
		cout << Ddate;
		cout << "|";
		cout.fill(' ');
		cout.width(15);
	cout << proizvedenie;
		cout << "|" << endl;
		};
public:void read() {
	filein >> name;
	filein >> surname;
	filein >> Bdate;
	filein >> Ddate;
	filein >> proizvedenie;
}
	   void save() {
		   fileout << name << "  ";
		   fileout << surname << "  ";
		   fileout << Bdate << "  ";
		   fileout << Ddate << "  ";
		   fileout << proizvedenie << "  ";
		   fileout << "\n";
	   }
};
vector<poet> poets;
void print();
void add();
void del();
void edit();
void search();
int n;
bool ex;
void menu() {

	int num;
	system("cls");
	printf_s("1)View poets\n");
	printf_s("2)ADD poet\n");
	printf_s("3)Delete Poet\n");
	printf_s("4)Edit\n");
	printf_s("5)Search\n");
	printf_s("6)Exit\n");
	printf_s("Vvedite nomer punkta menu\n");
	scanf_s("%i", &num);
	switch (num)
	{	case 1:
		print();
		break;
	case 2: add();
		break;
	case 3: del();
		break;
	case 4:edit();
		break;
	case 5:search();
		break;
	case 6:fileout.open("input.txt");
		for (size_t i = 0; i < poets.size(); i++)
		{
			poets[i].save();
		}
		filein.close();
		fileout.close();
		ex = true;
		break;
	}
}
void nMenu() {
	nnum = 0;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
	bool numString[6] = {1,0,0,0,0,0};
	SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY); system("cls");
	while (!ex) {
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		system("cls");
		if (numString[0] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("1.View poets\n");
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		if (numString[1] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("2.ADD poet\n");
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		if (numString[2] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("3.Delete Poet\n");
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		if (numString[3] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("4.Edit\n");
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		if (numString[4] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("5.Search\n");
		SetConsoleTextAttribute(hConsoleHandle, BACKGROUND_INTENSITY);
		if (numString[5] == 1) { SetConsoleTextAttribute(hConsoleHandle, x); };
		printf_s("6.Exit\n");
	 int code = _getch();
		switch (code) {
		case 72:nnum--;
			break;  //up
		case 80:nnum++;
			break;//down
		case 13: {switch (nnum)
		{
		case 0:
			print();
			break;
		case 1: add();
			break;
		case 2: del();
			break;
		case 3:edit();
			break;
		case 4:search();
			break;
		case 5:fileout.open("input.txt", ios_base::trunc);
			for (size_t i = 0; i < poets.size(); i++)
			{
				poets[i].save();
			}
			filein.close();
			fileout.close();
			ex = true;
			break;
		}
		}
				 break;//ENTER
		};
zanul6(numString);
	};
};
void base() {
	ex = false;
	filein.open("input.txt");
	while (!filein.eof()) {
		poet p;
		p.read();
		poets.push_back(p);
	}
	poets.pop_back();
	nMenu();
}
void print() {
	system("cls");
	printf_s("|          Imya|       Familiya|  Data rozdenia|    Data smerti|   Proizvedenie|\n");
	for (size_t i = 0; i < poets.size(); i++)poets[i].print();
	_getch();
};
void add() {
	int k;
	printf_s("Vvedite chislo poetov dlya dobavlenia\n");
	scanf_s("%i", &k);
	printf_s("Vvedite Familiu,imya,datu rozdenia,smerti, i proizvedenie\n");
	poet p;
	for (int i = 0; i < k; i++) {
		cin >> p.name >> p.surname >> p.Bdate >> p.Ddate >> p.proizvedenie;
		poets.push_back(p);
	}
}
void del() {
	printf_s("Vvedite nomer udalyaemogo elementa\n");
	int n;
	scanf_s("%i", &n);
	if (n <= poets.size() + 1) {
		poets.erase(poets.begin() + n - 1);
	}
	else printf_s("Oshibka\n");
};
void search() {
	printf_s("Vvedite familiu iskomogo poeta\n");
	string name;
	//cin.ignore();
	getline(cin, name);
	int i;
	bool s = false;
	for (i = 0; i < poets.size(); i++) {
		if (poets[i].surname == name) {
			s = true; poets[i].print();
		}
	}
	if (!s) printf_s("Ne naideno\n");
	_getch();
}
void edit() {
	printf_s("Vvedite nomer redaktiruemogo elementa\n");
	int i;
	scanf_s("%i", &i);
	i--;
	poets[i].print();
	printf_s("Vvedite Familiu,imya,datu rozdenia,smerti, i proizvedenie\n");
	cin >> poets[i].name >> poets[i].surname >> poets[i].Bdate >> poets[i].Ddate >> poets[i].proizvedenie;
	poets[i].print();
	_getch();
}
