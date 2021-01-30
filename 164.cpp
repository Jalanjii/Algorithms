#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>


using namespace std;

//Data Structure
struct DEQueue
{
	void enqueueFront(int value);
	void  enqueueBack(int value);
	int dequeueFront();
	int dequeueBack();
	bool empty();

private:
	struct Node
	{
		int value;
		Node* next;
		Node* prev;


		Node(int value)
			: value(value), next(nullptr), prev(nullptr)
		{};
	};
	Node* head = nullptr;
	Node* tail = nullptr;
};

void DEQueue::enqueueFront(int value)
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

void DEQueue::enqueueBack(int value)
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

int DEQueue::dequeueFront()
{
	if (!head)
	{
		throw out_of_range("queue empty");
	}

	int value = head->value;
	Node* tmp = head;
	head = head->next;
	if (head)
		head->prev = nullptr;
	if (!head)
		tail = nullptr;
	delete tmp;
	return value;
}

int DEQueue::dequeueBack()
{
	if (!head)
	{
		throw out_of_range("queue empty");
	}

	int value = tail->value;
	Node* tmp = tail;
	tail = tail->prev;
	if (tail)
		tail->next = nullptr;
	if (!tail)
		head = nullptr;
	delete tmp;
	return value;
}

bool DEQueue::empty()
{
	return head == nullptr;
}


//Problem Solution
bool check(int a[], int count) {
	if (count != 3)
		return false;
	if (a[0] != a[1] || a[1] != a[2] || a[0] != a[2])
		return false;
	return true;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	struct DEQueue deque;

	int m, side;
	char color;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> side >> color;
		int a[3], count = 0;
		if (side == 1) {
			deque.enqueueFront(color);
			for (int j = 0; j < 3 && !deque.empty(); j++)
				a[count++] = deque.dequeueFront();
			if (!check(a, count)) {
				for (int j = count - 1; j >= 0; j--)
					deque.enqueueFront(a[j]);
			}
		}
		else {
			deque.enqueueBack(color);
			for (int j = 0; j < 3 && !deque.empty(); j++)
				a[count++] = deque.dequeueBack();
			if (!check(a, count)) {
				for (int j = count - 1; j >= 0; j--)
					deque.enqueueBack(a[j]);
			}
		}
	}

	if (deque.empty())
		cout << "-1";

	while (!deque.empty())
		cout << char(deque.dequeueFront()) << " ";

	return 0;
}