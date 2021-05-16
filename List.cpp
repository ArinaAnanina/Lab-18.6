#include <iostream>
#include "List.h"
using namespace std;
List::List(int size)
{
	this->last = 0;
	this->first = 0;
	this->size = 0;
	for (int i = 0; i < size; i++) {
		int* data = new int;
		cin >> (*data);
		this->addItem(*data);
	}
}

List::List(List& list)
{
	this->last = 0;
	this->first = 0;
	this->size = 0;
	*this = list;
}

List::~List()
{
	ListItem* current = this->first;
	while (current) {
		ListItem* rem = current;
		current = current->next;
		delete rem;
	}
}

Iterator List::First() {
	return Iterator(*first);
}

Iterator List::Last() {
	return Iterator(*last);
}

void List::addItem(int value)
{
	ListItem* item = new ListItem;
	item->data = value;
	item->next = 0;

	if (!this->first) {
		this->first = item;
	}
	if (this->last) {
		this->last->next = item;
		this->last = item;
	}
	else {
		this->last = item;
	}

	this->size++;
}

List& List::operator=(const List& list)
{
	if (this == &list)
	{
		return *this;
	}

	// Очистка
	if (this->size) {
		this->~List();
		this->size = 0;
		this->last = 0;
		this->first = 0;
	}

	// Наполнение
	ListItem* item = list.first;
	while (item) {
		this->addItem(item->data);
		item = item->next;
	}

	return *this;
}

ListItem* List::operator[](int index)
{
	if (index > size) {
		return new ListItem;
	}
	int i = 0;
	ListItem* item = this->first;
	while (i < index && item) {
		item = item->next;
		i++;
	}

	return item;
}

List List::operator+(const int value)
{
	ListItem* item = this->first;
	while (item) {
		item->data = item->data + value;
		item = item->next;
	}

	return *this;
}

int List::operator()()
{
	return this->size;
}

ostream& operator<<(ostream& out, const List& list)
{
	ListItem* item = list.first;
	while (item) {
		out << item->data << endl;
		item = item->next;
	}

	return out;
}

istream& operator>>(istream& in, List& list)
{
	ListItem* item = list.first;
	while (item) {
		in >> item->data;
		item = item->next;
	}
	return in;
}