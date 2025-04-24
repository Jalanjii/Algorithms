#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

struct DLList
{
	struct Node {
		int value;
		Node* next;
		Node* prev;


		Node(int value)
			: value(value), next(nullptr), prev(nullptr)
		{};
	};

	void insertFront(int value);
	void  insertBack(int value);
	int removeFront();
	int removeBack();
	bool empty();
	Node* begin() { return head; };
	Node* end() { return nullptr; };

private:

	
	Node* head = nullptr;
	Node* tail = nullptr;
};

void DLList::insertFront(int value)
{
	Node* tmp = new Node(value);
	if (head)
	{
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}
	else
	{
		tail = head = tmp;
	}
}

void DLList::insertBack(int value)
{
	Node* tmp = new Node(value);
	if (tail)
	{
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		head = tail = tmp;
	}
}

int DLList::removeFront()
{
	if (!head)
	{
		throw out_of_range("list empty");
	}

	int value = head->value;
	Node* tmp = head;
	head = head->next;
	if (head)
		head->prev = nullptr;
	delete tmp;
	return value;
}

int DLList::removeBack()
{
	if (!head)
	{
		throw out_of_range("list empty");
	}

	int value = tail->value;
	Node* tmp = tail;
	tail = tail->prev;
	if (tail)
		tail->next = nullptr;
	else
		head = nullptr;
	delete tmp;
	return value;
}

bool DLList::empty()
{
	return head == nullptr;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	DLList lst;

	int entry;

	while (cin >> entry) {
		lst.insertBack(entry);
	}

	for (auto i = lst.begin(); i != lst.end(); i = i->next) {
		cout << i->value << " ";
	}

	return 0;
}