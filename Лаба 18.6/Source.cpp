#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	cout << "�������� ������ �� 5 ���������: " << endl;
	List list_a(5);
	List list_b = list_a;
	cout << "����������� �����������: " << endl;
	List list(list_b);
	cout << list << endl;
	cout << "����������� ��������� (+5)" << endl;
	list + 5;
	cout << list << endl;
	cout << "��������� � ��������: " << endl;
	cout << "Item[2]: " << endl << list[2]->data << endl;
	cout << "����� ������� ������: "<< endl;
	cout << "Size: " << list() << endl;

	Iterator iter = list.First();
	iter++;
	iter++;
	cout << "��������� ��������� �� 2 �������: " << endl;
	cout << *iter << endl << endl;

	cout << "����� ������ � ������� ���������: " << endl;
	for (Iterator i = list.First(); !i.isOut(); i++) {
		cout << *i << endl;
	}

	return 0;
}