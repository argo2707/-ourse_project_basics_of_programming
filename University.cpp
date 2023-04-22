#include "University.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<fstream>
#include<Windows.h>
using namespace std;

void University::add()
{
	int k = 1;
	char* tempfam = new char;
	char* tempiniz = new char;
	int tempnumber;
	cout << "Введите фамилию" << endl;
	cin >> tempfam;
	while (k != 0)
	{
		if (!((tempfam[0] >= 'А') && (tempfam[0] <= 'Я')))
		{
			cout << "Введите корректно фамилию (Пример: Иванов)" << endl;
			cin >> tempfam;
		}
		for (int i = 1; i < strlen(tempfam); i++)
		{
			if (!((tempfam[i] >= 'а') && (tempfam[i] <= 'я')))
			{
				cout << "Введите корректно фамилию (Пример: Иванов)" << endl;
				cin >> tempfam;
				break;
			}
			if (i == (strlen(tempfam) - 1))
				k = 0;
		}

	}
	cout << "Введите инициалы" << endl;
	cin >> tempiniz;
	while (!((tempiniz[0] >= 'А') && (tempiniz[0] <= 'Я') && (tempiniz[2] >= 'А')
		&& (tempiniz[2] <= 'Я') && (tempiniz[1] == '.') && (tempiniz[3] == '.')))
	{
		cout << "Введите корректно инициалы (Пример: И.О.)" << endl;
		cin >> tempiniz;
	}
	cout << "Введите номер группы студента" << endl;
	cin >> tempnumber;
	while (!((tempnumber >= 1000) && (tempnumber < 10000)))
	{
		cout << "Введите корректно номер группы (Пример: 1234)" << endl;
		cin >> tempnumber;
	}
	cout << "Введите баллы студента (5 штук):" << endl;
	int temp;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		while (!((temp >= 0) && (temp <= 5)))
		{
			cout << "Диапозон от 0 до 5" << endl;
			cin >> temp;
		}
		data[quan].perform[i] = temp;
	}
	cout << "Данные студента: " << tempfam << " " << tempiniz << " Группа: " << tempnumber << endl;
	data[quan].fio = tempfam;
	data[quan].init = tempiniz;
	data[quan].number = tempnumber;
	quan++;
}

void University::Edit()
{
	auto *temp = Search();
	int k = 1;
	if (temp == nullptr)
		return;
	system("cls");
	cout << "Редактировать:" << endl;
	cout << "1 - Фамилию" << endl;
	cout << "2 - Инициалы:" << endl;
	cout << "3 - Номер группы" << endl;
	cout << "4 - Успеваемость" << endl;
	cin >> k;
	system("cls");
	while (k != 0)
	{

		if (k == 1)
		{
			cout << "Введите фамилию" << endl;
			cin >> temp->fio;
			while (k != 0)
			{
				if (!((temp->fio[0] >= 'А') && (temp->fio[0] <= 'Я')))
				{
					cout << "Введите корректно фамилию (Пример: Иванов)" << endl;
					cin >> temp->fio;
				}
				for (int i = 1; i < strlen(temp->fio); i++)
				{
					if (!((temp->fio[i] >= 'а') && (temp->fio[i] <= 'я')))
					{
						cout << "Введите корректно фамилию (Пример: Иванов)" << endl;
						cin >> temp->fio;
						break;
					}
					if (i == (strlen(temp->fio) - 1))
						k = 0;
				}

			}
		}

		if (k == 2)
		{
			cout << "Введите инициалы" << endl;
			cin >> temp->init;
			while (!((temp->init[0] >= 'А') && (temp->init[0] <= 'Я') && (temp->init[2] >= 'А')
				&& (temp->init[2] <= 'Я') && (temp->init[1] == '.') && (temp->init[3] == '.')))
			{
				cout << "Введите корректно инициалы (Пример: И.О.)" << endl;
				cin >> temp->init;
			}
		}
		if (k == 3)
		{
			cout << "Введите номер группы студента" << endl;
			cin >> temp->number;
			while (!((temp->number >= 1000) && (temp->number < 10000)))
			{
				cout << "Введите корректно номер группы (Пример: 1234)" << endl;
				cin >> temp->number;
			}
		}
		if (k == 4)
		{
			cout << "Введите баллы студента (5 штук):" << endl;
			int tempr;
			for (int i = 0; i < 5; i++)
			{
				cin >> tempr;
				while (!((tempr >= 0) && (tempr <= 5)))
				{
					cout << "Диапозон от 0 до 5" << endl;
					cin >> tempr;
				}
				temp->perform[i] = tempr;
			}
		}
		system("cls");

		cout << "Редактировать:" << endl;
		cout << "1 - Фамилию" << endl;
		cout << "2 - Инициалы:" << endl;
		cout << "3 - Номер группы" << endl;
		cout << "4 - Успеваемость" << endl;
		cout << "Если всё отредактировали, то введите - 0" << endl;
		cin >> k;
		system("cls");
	}
}

void University::Delete()
{
	auto temp = Search();
	int k = 1;
	if (temp == nullptr)
		return;
	system("cls");
	for (int i = 0; i < quan; i++)
	{
		if (temp == &data[i])
		{
			for (int j = i; j < quan - 1; j++)
			{
				data[i] = data[i + 1];

			}
			data[quan - 1].fio = nullptr;
			data[quan - 1].init = nullptr;
			data[quan - 1].number = 0;
			cout << "Студент удален" << endl;
		}
	}
	quan--;
}

STUDENT* University::Search()
{
	char* temp = new char;
	int k = 0;
	cout << "Введите фамилию для поиска студента" << endl;
	cin >> temp;
	for (int i = 0; i < quan; i++)
	{
		k = 0;
		for (int j = 0; j < strlen(temp); j++)
		{
			if (temp[j] == data[i].fio[j])
				k++;
		}
		if (k == strlen(temp))
		{
			cout << "Данные студента: " << data[i].fio << " " << data[i].init << " Группа: " << data[i].number << "\n" << endl;
			cout << "Этого студента вы искали?" << endl;
			cout << "Да-1, нет-0\n";
			cin >> k;
			if (k == 1) {
				cout << "\nСтудент найден!" << endl;
				return &data[i];
			}
			else if (k != 0)
			{
				cout << "Да - 1, Нет - 0\n";
				cin >> k;
			}
			system("cls");
		}
	}
	cout << "Студент не найден!" << endl;
	return nullptr;
}

void University::sort()
{
	cout << "Сортируется!" << endl;
	STUDENT temp;
	int k = 0;
	for (int j = 0; j < quan; j++)
	{
		for (int i = 0; i < quan-1; i++)
		{
			while ((k != strlen(data[i].fio))&&(k != strlen(data[i+1].fio)))
			{
				if ((int)data[i].fio[k] > (int)data[i + 1].fio[k])
				{
					temp = data[i];
					data[i] = data[i + 1];
					data[i + 1] = temp;
					break;
				}
				else if ((int)data[i].fio[k] == (int)data[i + 1].fio[k])
					k++;
				else
					break;
			}

		}
	}
	cout << "Отсортированно!" << endl;
}

void University::addfail()
{
	ofstream out("text.txt");
	for (int i = 0; i < quan; i++)
	{
		out << data[i].fio << " " << data[i].init << "  " << data[i].number;
		out << " ";
		for (int j = 0; j < 5; j++)
		{
			out << data[i].perform[j] << " ";
		}
		out << endl;
	}
	cout << "Добавлено" << endl;
	out.close();
}

void University::aversear()
{
	double temp;
	cout << "Введите среднее значение:" << endl;
	cin >> temp;
	cout << "Данные студентов, чей средний балл не ниже указанного" << endl;
	for (int i = 0; i < quan; i++)
	{
		if (srscore(data[i].perform) >= temp)
		{
			cout << data[i].fio << " " << data[i].init << "  " << data[i].number;
			cout << "  Успеваемость: ";
			for (int j = 0; j < 5; j++)
			{
				cout << data[i].perform[j] << " ";
			}
			cout << endl;
		}
	}
}

void University::output()
{
	cout << "_______________________________________________________________" << endl;
	cout << "|   Фамилия и инициалы    |  Номер группы |    Успеваемость   |" << endl;
	cout << "_______________________________________________________________" << endl;
	for (int i = 0; i < quan; i++)
	{
		cout << "|" << setw(19) << left << setfill(' ') << data[i].fio << setw(5) << data[i].init << " " << "|";
		cout << "     " << data[i].number << "      |     ";
		for (int j = 0; j < 5; j++)
		{
			cout << data[i].perform[j] << " ";
		}
		cout << "    |" << endl;
	}
	cout << "_______________________________________________________________" << endl;
}

double University::srscore(int perf[5])
{
	int sr = 0;
	for (int i = 0; i < 5; i++)
	{
		sr += perf[i];
	}

	return sr / 5.0;
}
