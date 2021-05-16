#pragma once
#include <iostream>

using namespace std;
struct ListItem
{
	int data;
	ListItem* next;
};

class Iterator
{
	ListItem* current;
public:
	Iterator(ListItem& item)
	{
		this->current = &item;
	}
	bool isOut() {
		return this->current == 0;
	}
	bool operator== (const Iterator& it)
	{
		return this->current->data == it.current->data;
	}
	bool operator!= (const Iterator& it)
	{
		return this->current->data != it.current->data;
	}
	Iterator operator++(int)
	{
		if (!this->isOut()) {
			this->current = this->current->next;
		}
		return *this;
	}
	int operator*()
	{
		return (!this->isOut()) ? this->current->data : 0;
	}
};

class List
{
	int size;
	ListItem* first;
	ListItem* last;
	void addItem(int value);
public:
	List(int size);
	List(List& list);
	~List();

	Iterator First();
	Iterator Last();

	List& operator=(const List& list);

	ListItem* operator[](int index);
	List operator+(const int value);
	int operator()();

	friend ostream& operator<< (ostream& out, const List& list);
	friend istream& operator>> (istream& in, List& list);
};