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
	/*void insert_pos(int value, int pos);
	void remove(int value);
	void swapElement(int a, int b);
	bool empty();
	void clear();*/
	Node* MergeSort(Node* node_a);
	Node* Merge(Node* node_a, Node* node_b);
	Node* Split(Node* node_a);
	void sorted();
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

List::Node* List::MergeSort(Node* node_a) {
	Node *node_b;

	if (!node_a)
		return nullptr;

	else if (node_a->next == nullptr)
		return node_a;

	else {
		node_b = Split(node_a);
		return Merge(MergeSort(node_a), MergeSort(node_b));
	}
}

List::Node* List::Merge(Node* node_a, Node* node_b) {
	if (!node_a)
		return node_b;

	else if (!node_b)
		return node_a;

	else if (node_a->value <= node_b->value) {

		node_a->next = Merge(node_a->next, node_b);
		return node_a;
	}

	else {
		node_b->next = Merge(node_a, node_b->next);
		return node_b;
	}
}

List::Node* List::Split(Node* node_a) {
	Node* node_b;

	if (!node_a || !node_a->next)
		return nullptr;

	else {
		node_b = node_a->next;
		node_a->next = node_b->next;
		node_b->next = Split(node_b->next);
		return node_b;
	}
}

void List::sorted() {
	head = MergeSort(head);//this adjustment is enough, because we output till nullptr
	if (head) {//if pushing back values, this tail adjustment is crucial.
			   //Or in case of reverse iterating for doubly linked lists
		tail = head;
		while (tail->next)
			tail = tail->next;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	List lst;

	int x;
	while (cin >> x) {
		lst.insert(x);
	}

	lst.sorted();

	for (auto i = lst.begin(); i != lst.end(); i = i->next) {
		cout << i->value << " ";
	}

	return 0;
}