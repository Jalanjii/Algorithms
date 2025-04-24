#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>


using namespace std;

struct List {
	struct Node {

		int value;
		Node* next;

		Node(int value)
			: value(value), next(nullptr)
		{};
	};

	void insert(int value);
	void insert_pos(int value, int pos);
	void remove(int value);
	void swp(int a, int b);
	bool empty();
	void clear();
	Node* begin() { return head; };
	Node* end() { return nullptr; };

private:
	Node* head = nullptr;
	Node* tail = nullptr;
};

void List::insert(int value) {
	Node* tmp = new Node(value);
	if (head)
	{
		tail = tail->next = tmp;
	}
	else
	{
		head = tail = tmp;
	}
}

void List::insert_pos(int value, int pos) {
	Node* tmp = new Node(value);
	if (!head)
		head = tmp;

	else if (pos == 0) {
		tmp->next = head;
		head = tmp;
	}

	else {

		Node *current = head;
		int n = 1;

		while (current != tail && n != pos) {
			current = current->next;
			n++;
		}

		tmp->next = current->next;
		current->next = tmp;
	}
}

void List::remove(int value) {

	if (head->value == value) {
		Node* current = head;
		head = head->next;
		delete current;
	}

	else {

		Node* previous = head;
		Node* current = head->next;
		while (current != nullptr) {
			if (current->value == value) {
				previous->next = current->next;
				delete current;
				break;
			}
			else {
				previous = current;
				current = current->next;
			}
		}
	}
}

void List::swp(int a, int b) {
	
	Node* a_node = nullptr;
	Node* b_node = nullptr;
	for (auto i = begin(); i != end(); i = i->next) {
		if (i->value == a)
			a_node = i;
		if (i->value == b)
			b_node = i;
	}
	if (a_node && b_node)
		swap(a_node->value, b_node->value);
}

bool List::empty() {
	return head == nullptr;
}

void List::clear() {

	while (head) {
		auto tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	List lst;

	int x, y, tmp;
	cin >> x >> y;
	while (cin >> tmp) {
		lst.insert(x);
		x = y;
		y = tmp;
	}

	lst.swp(x, y);

	for (auto i = lst.begin(); i != lst.end(); i = i->next) {
		cout << i->value << " ";
	}

	return 0;
}