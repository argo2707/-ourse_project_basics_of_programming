#include <iostream>
#include <iomanip>
#include <conio.h>
#include<Windows.h>
#include "University.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int temp = 1;
	University GUAP;

	while (temp != 0)
	{
		cout << "____________________________________________________" << endl;
		cout << "|������� �����:                                     |" << endl;
		cout << "|���������� - 1                                     |" << endl;
		cout << "|�������������� - 2                                 |" << endl;
		cout << "|�������� - 3                                       |" << endl;
		cout << "|����� �� ������� - 4                               |" << endl;
		cout << "|���������� - 5                                     |" << endl;
		cout << "|���������� � ���� - 6                              |" << endl;
		cout << "|����� ��������� �� �������� ����� - 7              |" << endl;
		cout << "|����� �� ����� - 8                                 |" << endl;
		cout << "|����� - 0                                          |\n";
		cout << "|___________________________________________________|" << endl;
		cin >> temp;
		system("cls");
		if (temp == 1)
			GUAP.add();
		if (temp == 2)
			GUAP.Edit();
		if (temp == 3)
			GUAP.Delete();
		if (temp == 4)
			GUAP.Search();
		if (temp == 5)
			GUAP.sort();
		if (temp == 6)
			GUAP.addfail();
		if (temp == 7)
			GUAP.aversear();
		if (temp == 8)
			GUAP.output();
		if (temp == 0)
			break;
		cout << "\n������� ����� ������� ��� �����������..";
		_getch();
		system("cls");
	}

}