#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
struct Data {
	int day;
	int month;
	int year;
};
struct delivery {
	string name;
	string country;
};
struct flower {
	string name;
	string color;
	int price;
	int number;
	Data dat;
	delivery deliver;
};
vector <flower> spisok;
vector <int> cheKK; // тут хранятся индексы цветов из вектора выше, для того, что бы потом по индексам выписать чек


void add_flower(string name, string color, int price, int number, Data data, delivery deliv) {
	flower NEW;
	NEW.name = name;
	NEW.color = color;
	NEW.price = price;
	NEW.number = number;
	NEW.dat = data;
	NEW.deliver = deliv;
	spisok.push_back(NEW);
}

void display() {
	if (spisok.size() != 0)
	{
		for (int i = 0; i < spisok.size(); i++) {
			cout << " Название: " << spisok[i].name << endl;
			cout << " Цвет: " << spisok[i].color << endl;
			cout << " Цена: " << spisok[i].price << endl;
			cout << " Кол-ство: " << spisok[i].number << endl;
			cout << " Дата доставки: " << spisok[i].dat.day << "." << spisok[i].dat.month << "." << spisok[i].dat.year << "." << endl;
			cout << " Поставщик: " << spisok[i].deliver.name << ", " << spisok[i].deliver.country << endl;
			cout << "-------------------\n";
		}
	}
	else
		cout << "Список пуст!" << endl;
}

void outfile(void)
{
	cout << "Ввод пути для файла (включая его название в расширением .txt)" << endl;
	cout << "Пример: D:\\\Desktop\\spisok.txt" << endl;
	cout << "->";
	string put;
	cin >> put;
	ofstream out(put, ios_base::trunc);
	if (out.is_open())
	{
		cout << "Список всех цветов был помещен по заданному пути!" << endl;
		if (spisok.size() != 0)
		{
			for (int i = 0; i < spisok.size(); i++) {
				out << " Название: " << spisok[i].name << endl;
				out << " Цвет: " << spisok[i].color << endl;
				out << " Цена: " << spisok[i].price << endl;
				out << " Кол-ство: " << spisok[i].number << endl;
				out << " Дата доставки: " << spisok[i].dat.day << "." << spisok[i].dat.month << "." << spisok[i].dat.year << "." << endl;
				out << " Поставщик: " << spisok[i].deliver.name << ", " << spisok[i].deliver.country << endl;
				out << "-------------------\n";
			}
		}
		else
			cout << "Список пуст!" << endl;
	}
	else
		cout << "Невозможно создать файл по заданному пути!" << endl;
}

void redactor(int pos, string name, string color, int price, int number, Data data, delivery deliv)
{
	spisok[pos].name = name;
	spisok[pos].color = color;
	spisok[pos].price = price;
	spisok[pos].number = number;
	spisok[pos].dat = data;
	spisok[pos].deliver = deliv;
}

int poiskprise(string name)
{
	for (int i = 0; i < spisok.size(); i++) {
		if (spisok[i].name == name)
		{
			cheKK.push_back(i);
			return spisok[i].price;
		}
	}
	return 0;
}

void check()
{
	int n = 1, total = 0;
	while (n != 0)
	{
		system("cls");
		cout << "Общая стоимость: " << total << endl;
		cout << "Добавить  (1-Да, 0-Нет)" << endl;
		int a;
		cin >> a;
		if (a == 1)
		{
			string N;
			int C,stoim;
			cout << "Введите название цветка ->";
			cin >> N;
			stoim = poiskprise(N);
			if (stoim == 0)
			{
				cout << "Такого цветка не было найдено!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "Введите колличество ->";
				cin >> C;
				total += stoim * C;
				cheKK.push_back(stoim * C);
				cheKK.push_back(C);
			}
			system("cls");
		}
		else 
		{
			system("cls");
			cout << "Общая стоимость: " << total << endl;
			cout << "Составить чек? (1-Да, 0-Нет)" << endl;
			int a;
			cin >> a;
			if (a == 1)
			{
				cout << "Ввод пути для файла (включая его название в расширением .txt)" << endl;
				cout << "Пример: D:\\\Desktop\\check.txt" << endl;
				cout << "->";
				string put;
				cin >> put;
				ofstream fout(put, ios_base::trunc);
				if (fout.is_open())
				{
					fout << "Произведена покупка товаров:" << endl;
					for (int i = 0; i < cheKK.size(); i+=3)
					{
							fout << "   " << spisok[cheKK[i]].name << " " << cheKK[i + 2] << "шт. Стоимость: " << cheKK[i + 1] << endl;
							spisok[cheKK[i]].number -= cheKK[i + 2];  
					}
					fout << "------------------------------------" << endl;
					fout << "Общая стоимость: " << total << endl;
					fout << "------------------------------------" << endl;
					fout.close();
					cout << "Чек успешно помещен по заданному пути!" << endl;
					system("pause");
				}
				else if (!fout.is_open())
				{
					cout << "Чек невозможно поместить по заданному пути!" << endl;
					system("pause");
				}
			}	
			else
			{
				cheKK.clear();
				n = 0;
			} 
		}
	}
}

int poisk(string name)
{
	for (int i = 0; i < spisok.size(); i++)
	{
		if (spisok[i].name == name)
		{
			cout << " Название: " << spisok[i].name << endl;
			cout << " Цвет: " << spisok[i].color << endl;
			cout << " Цена: " << spisok[i].price << endl;
			cout << " Кол-ство: " << spisok[i].number << endl;
			cout << " Дата доставки: " << spisok[i].dat.day << "." << spisok[i].dat.month << "." << spisok[i].dat.year << "." << endl;
			cout << " Поставщик: " << spisok[i].deliver.name << ", " << spisok[i].deliver.country << endl;
			cout << "-------------------\n";
			return i;
		}
	}
	cout << " Ошибка, цветок не найден.\n ";
	return -1;
}

void deliver(string name) {
	for (int i = 0; i < spisok.size(); i++)
	{
		if (name == spisok[i].deliver.name) {
			cout << "Данные о поставщике: " << endl;
			cout << "Поставщик: " << spisok[i].deliver.name << endl;
			cout << "Страна поставщика: " << spisok[i].deliver.country << endl;
		}
	}
	cout << "Такого поставщика нет в нашей базе!" << endl;
}

void delet(string name) {
	vector<flower>::iterator it = spisok.begin();
	for (int i = 0; i < spisok.size(); i++)
	{
		if (spisok[i].name == name) {
			advance(it, i);
			spisok.erase(it);
		}
		else {
			cout << "Такого цветка нет в нашей базе!" << endl;
		}
	}
}

void menu() {
	cout << " Выберите действие: " << endl;
	cout << "(1) Добавление новых цветов" << endl;
	cout << "(2) Удаление цветов" << endl;
	cout << "(3) Изменение параметров цветов" << endl;
	cout << "(4) Расчет стоимости/составление чека" << endl;
	cout << "(5) Поиск цветов" << endl;
	cout << "(6) Вывод информации о поставщике" << endl;
	cout << "(7) Список всех цветов" << endl;
	cout << "(8) Записать список всех цветов в файл" << endl;
	cout << "(0) Выход из программы." << endl;
}

int main()
{
	int num, P;
	string N, M, D, C;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (int q = 1 != 0)
	{
		menu();
		cin >> q;
		if (q == 1)

		{
			system("cls");
			Data dat;
			delivery deliv;
			cout << " Название: " << endl;
			cin >> N;
			cout << "Цвет: " << endl;
			cin >> C;
			cout << "Цена: " << endl;
			cin >> P;
			cout << "Количество: " << endl;
			cin >> num;
			cout << "Дата доставки (день -> месяц -> год): " << endl;
			cin >> dat.day;
			cin >> dat.month;
			cin >> dat.year;
			cout << "Поставщик: " << endl;
			cin >> deliv.name;
			cout << "Страна поставщика: " << endl;
			cin >> deliv.country;

			add_flower(N, C, P, num, dat, deliv);
			system("pause");
			system("cls");

		}
		if (q == 2)
		{
			system("cls");
			string nm;
			cout << "Какой цветок удалить? " << endl;
			cin >> nm;
			delet(nm);
			cout << "Удалено!" << endl;
			system("pause");
			system("cls");
		}
		if (q == 3)
		{
			string n;
			cout << "Введите название заменяемого цветка ->";
			cin >> n;
			system("cls");
			int pos = poisk(n);
			if (pos != -1)
			{
				cout << "ИЗМЕНИТЬ ЭТОТ ЦВЕТОК? (1-Да, 0-Нет)" << endl;
				int a;
				cin >> a;
				system("cls");
				if (a == 1)
				{
					Data dat;
					delivery deliv;
					cout << " Название: " << endl;
					cin >> N;
					cout << "Цвет: " << endl;
					cin >> C;
					cout << "Цена: " << endl;
					cin >> P;
					cout << "Количество: " << endl;
					cin >> num;
					cout << "Дата доставки (день -> месяц -> год): " << endl;
					cin >> dat.day;
					cin >> dat.month;
					cin >> dat.year;
					cout << "Поставщик: " << endl;
					cin >> deliv.name;
					cout << "Страна поставщика: " << endl;
					cin >> deliv.country;

					redactor(pos, N, C, P, num, dat, deliv);
					system("pause");
					system("cls");
				}
			}
		}
		if (q == 4)
		{
			check();
			system("pause");
			system("cls");
		}
		if (q == 5) {
			system("cls");
			string k;
			cout << "Название цветка: " << endl;
			cin >> k;
			poisk(k);
			system("pause");
			system("cls");
		}
		if (q == 6) {
			system("cls");
			string g;
			cout << " Введите название поставщика: " << endl;
			cin >> g;
			deliver(g);
			system("pause");
			system("cls");
		}
		if (q == 7) {
			system("cls");
			display();
			system("pause");
			system("cls");
		}
		if (q == 8)
		{
			outfile();
			system("pause");
			system("cls");
		}
		if (q == 0)
		{
			return 0;
		}
	}
}

