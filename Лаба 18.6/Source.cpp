#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	cout << "Создание списка на 5 элементов: " << endl;
	List list_a(5);
	List list_b = list_a;
	cout << "Конструктор копирования: " << endl;
	List list(list_b);
	cout << list << endl;
	cout << "Прибавление константы (+5)" << endl;
	list + 5;
	cout << list << endl;
	cout << "Обращение к элементу: " << endl;
	cout << "Item[2]: " << endl << list[2]->data << endl;
	cout << "Вывод размера списка: "<< endl;
	cout << "Size: " << list() << endl;

	Iterator iter = list.First();
	iter++;
	iter++;
	cout << "Установка итератора на 2 элемент: " << endl;
	cout << *iter << endl << endl;

	cout << "Вывод списка с помощью итератора: " << endl;
	for (Iterator i = list.First(); !i.isOut(); i++) {
		cout << *i << endl;
	}

	return 0;
}