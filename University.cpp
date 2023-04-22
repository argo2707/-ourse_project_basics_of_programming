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
	cout << "������� �������" << endl;
	cin >> tempfam;
	while (k != 0)
	{
		if (!((tempfam[0] >= '�') && (tempfam[0] <= '�')))
		{
			cout << "������� ��������� ������� (������: ������)" << endl;
			cin >> tempfam;
		}
		for (int i = 1; i < strlen(tempfam); i++)
		{
			if (!((tempfam[i] >= '�') && (tempfam[i] <= '�')))
			{
				cout << "������� ��������� ������� (������: ������)" << endl;
				cin >> tempfam;
				break;
			}
			if (i == (strlen(tempfam) - 1))
				k = 0;
		}

	}
	cout << "������� ��������" << endl;
	cin >> tempiniz;
	while (!((tempiniz[0] >= '�') && (tempiniz[0] <= '�') && (tempiniz[2] >= '�')
		&& (tempiniz[2] <= '�') && (tempiniz[1] == '.') && (tempiniz[3] == '.')))
	{
		cout << "������� ��������� �������� (������: �.�.)" << endl;
		cin >> tempiniz;
	}
	cout << "������� ����� ������ ��������" << endl;
	cin >> tempnumber;
	while (!((tempnumber >= 1000) && (tempnumber < 10000)))
	{
		cout << "������� ��������� ����� ������ (������: 1234)" << endl;
		cin >> tempnumber;
	}
	cout << "������� ����� �������� (5 ����):" << endl;
	int temp;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		while (!((temp >= 0) && (temp <= 5)))
		{
			cout << "�������� �� 0 �� 5" << endl;
			cin >> temp;
		}
		data[quan].perform[i] = temp;
	}
	cout << "������ ��������: " << tempfam << " " << tempiniz << " ������: " << tempnumber << endl;
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
	cout << "�������������:" << endl;
	cout << "1 - �������" << endl;
	cout << "2 - ��������:" << endl;
	cout << "3 - ����� ������" << endl;
	cout << "4 - ������������" << endl;
	cin >> k;
	system("cls");
	while (k != 0)
	{

		if (k == 1)
		{
			cout << "������� �������" << endl;
			cin >> temp->fio;
			while (k != 0)
			{
				if (!((temp->fio[0] >= '�') && (temp->fio[0] <= '�')))
				{
					cout << "������� ��������� ������� (������: ������)" << endl;
					cin >> temp->fio;
				}
				for (int i = 1; i < strlen(temp->fio); i++)
				{
					if (!((temp->fio[i] >= '�') && (temp->fio[i] <= '�')))
					{
						cout << "������� ��������� ������� (������: ������)" << endl;
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
			cout << "������� ��������" << endl;
			cin >> temp->init;
			while (!((temp->init[0] >= '�') && (temp->init[0] <= '�') && (temp->init[2] >= '�')
				&& (temp->init[2] <= '�') && (temp->init[1] == '.') && (temp->init[3] == '.')))
			{
				cout << "������� ��������� �������� (������: �.�.)" << endl;
				cin >> temp->init;
			}
		}
		if (k == 3)
		{
			cout << "������� ����� ������ ��������" << endl;
			cin >> temp->number;
			while (!((temp->number >= 1000) && (temp->number < 10000)))
			{
				cout << "������� ��������� ����� ������ (������: 1234)" << endl;
				cin >> temp->number;
			}
		}
		if (k == 4)
		{
			cout << "������� ����� �������� (5 ����):" << endl;
			int tempr;
			for (int i = 0; i < 5; i++)
			{
				cin >> tempr;
				while (!((tempr >= 0) && (tempr <= 5)))
				{
					cout << "�������� �� 0 �� 5" << endl;
					cin >> tempr;
				}
				temp->perform[i] = tempr;
			}
		}
		system("cls");

		cout << "�������������:" << endl;
		cout << "1 - �������" << endl;
		cout << "2 - ��������:" << endl;
		cout << "3 - ����� ������" << endl;
		cout << "4 - ������������" << endl;
		cout << "���� �� ���������������, �� ������� - 0" << endl;
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
			cout << "������� ������" << endl;
		}
	}
	quan--;
}

STUDENT* University::Search()
{
	char* temp = new char;
	int k = 0;
	cout << "������� ������� ��� ������ ��������" << endl;
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
			cout << "������ ��������: " << data[i].fio << " " << data[i].init << " ������: " << data[i].number << "\n" << endl;
			cout << "����� �������� �� ������?" << endl;
			cout << "��-1, ���-0\n";
			cin >> k;
			if (k == 1) {
				cout << "\n������� ������!" << endl;
				return &data[i];
			}
			else if (k != 0)
			{
				cout << "�� - 1, ��� - 0\n";
				cin >> k;
			}
			system("cls");
		}
	}
	cout << "������� �� ������!" << endl;
	return nullptr;
}

void University::sort()
{
	cout << "�����������!" << endl;
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
	cout << "��������������!" << endl;
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
	cout << "���������" << endl;
	out.close();
}

void University::aversear()
{
	double temp;
	cout << "������� ������� ��������:" << endl;
	cin >> temp;
	cout << "������ ���������, ��� ������� ���� �� ���� ����������" << endl;
	for (int i = 0; i < quan; i++)
	{
		if (srscore(data[i].perform) >= temp)
		{
			cout << data[i].fio << " " << data[i].init << "  " << data[i].number;
			cout << "  ������������: ";
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
	cout << "|   ������� � ��������    |  ����� ������ |    ������������   |" << endl;
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
