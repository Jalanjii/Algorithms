#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

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
	int n, k, temp;
	cin >> n >> k;

	int *minHeap = new int[k];
	int i;
	for (i = 0; i < k; i++) {
		cin >> minHeap[i];
		if (k == 1 && minHeap[i] == 1) {
			cout << 2;
			return 0;
		}
	}
		

	buildMinHeap(minHeap, k);

	for (i = k; i < n; i++)
	{
		cin >> temp;
		if (temp > minHeap[0])
		{
			minHeap[0] = temp;
			minHeapify(minHeap, k, 0);
		}
	}
	cout << minHeap[0];

	return 0;
}
--------
#define _CRT_SECURE_NO_WARNINGS //Interactor version
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

void minHeapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	if (l < n && arr[l] < arr[largest])
		largest = l;

	if (r < n && arr[r] < arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		minHeapify(arr, n, largest);
	}
}

void maxHeapify(int arr[], int n, int i)
{
	int smallest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	if (l < n && arr[l] > arr[smallest])
		smallest = l;

	if (r < n && arr[r] > arr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(arr[i], arr[smallest]);

		maxHeapify(arr, n, smallest);
	}
}

void buildMinHeap(int a[], int n) {
	for (int i = n / 2; i >= 0; i--)
		minHeapify(a, n, i);
}

void buildMaxHeap(int a[], int n) {
	for (int i = n / 2; i >= 0; i--)
		maxHeapify(a, n, i);
}

int kthsmallest(int heap[], int k, int n) {
	int i, temp;
	for (i = 0; i < k; i++)
		cin >> heap[i];

	buildMaxHeap(heap, k);

	for (i = k; i < n; i++) {
		cin >> temp;
		if (temp < heap[0]) {
			heap[0] = temp;
			maxHeapify(heap, k, 0);
		}
	}
	return heap[0];
}

int kthlargest(int heap[], int k, int n) {
	int i, temp;
	for (i = 0; i < k; i++)
		cin >> heap[i];

	buildMinHeap(heap, k);

	for (i = k; i < n; i++) {
		cin >> temp;
		if (temp > heap[0]) {
			heap[0] = temp;
			minHeapify(heap, k, 0);
		}
	}
	return heap[0];
}

int main() {//kth largest element    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, k1, f;
	cin >> n >> k;
	k1 = n - k + 1;


	if (k < k1) {
		if (k == 1) {
			int curr, next;
			cin >> curr;
			if (k == 1 && curr == 1) {
				cout << 2;
				return 0;
			}
			for (int i = 1; i < n; i++) {
				cin >> next;
				curr = max(curr, next);
			}
			cout << curr;
		}
		else {
			int *Heap = new int[k];
			cout << kthlargest(Heap, k, n);
		}
	}

	else {
		if (k1 == 1) {
			int curr, next;
			cin >> curr;
			if (k == 1 && curr == 1) {
				cout << 2;
				return 0;
			}
			for (int i = 1; i < n; i++) {
				cin >> next;
				curr = min(curr, next);
			}
			cout << curr;
		}
		else {
			int *Heap = new int[k1];
			cout << kthsmallest(Heap, k1, n);
		}
	}
	return 0;
}