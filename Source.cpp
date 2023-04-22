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
		cout << "|Введите цифру:                                     |" << endl;
		cout << "|Добавление - 1                                     |" << endl;
		cout << "|Редактирование - 2                                 |" << endl;
		cout << "|Удаление - 3                                       |" << endl;
		cout << "|Поиск по фамилии - 4                               |" << endl;
		cout << "|Сортировка - 5                                     |" << endl;
		cout << "|Добавление в файл - 6                              |" << endl;
		cout << "|Поиск студентов по среднему баллу - 7              |" << endl;
		cout << "|Вывод на экран - 8                                 |" << endl;
		cout << "|Выход - 0                                          |\n";
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
		cout << "\nНажмите любую клавишу для продолжения..";
		_getch();
		system("cls");
	}

}