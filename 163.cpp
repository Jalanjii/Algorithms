#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

//Data structure
struct Queue
{
	void enqueue(int value);
	int dequeue();
	bool empty();

private:
	struct Node
	{
		int value;
		Node* next;

		Node(int value)
			: value(value), next(nullptr)
		{};
	};
	Node* head = nullptr;
	Node* tail = nullptr;
};

void Queue::enqueue(int value)
{
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

bool Queue::empty()
{
	return head == nullptr;
}

int Queue::dequeue()
{
	if (!head)
	{
		throw out_of_range("queue empty");
	}

	int value = head->value;
	Node* tmp = head;
	head = head->next;
	delete tmp;
	return value;
}

//Problem Solution
void minHeapify(int a[], int n, int i)
{
	int l = 2 * i;
	int r = 2 * i + 1;
	int smallest = i;
	if (l<n && a[l]<a[smallest])
		smallest = l;
	if (r<n && a[r]<a[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(a[i], a[smallest]);
		minHeapify(a, n, smallest);
	}
}

void buildMinHeap(int a[], int n) {
	for (int i = n / 2; i >= 0; i--)
		minHeapify(a, n, i);
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, temp, res = 0, entry;
	cin >> n >> k;

	struct Queue queue;

	k = min(n, k);
	int *minHeap = new int[k];

	for (int i = 0; i < k; i++) {
		cin >> minHeap[i];
		res = max(minHeap[i], res);
	}


	buildMinHeap(minHeap, k);

	for (int i = k; i < n; i++)
	{
		cin >> entry;
		queue.enqueue(entry);

		while (!queue.empty()) {

			//minimum time = maximum of end times - (the beginning time = 0).
			temp = queue.dequeue();
			minHeap[0] += temp;
			res = max(minHeap[0], res);
			minHeapify(minHeap, k, 0);
		}
	}
	cout << res;
	return 0;
}