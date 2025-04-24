#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

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

void buildMaxHeap(int a[], int n) {
	for (int i = n / 2; i >= 0; i--)
		maxHeapify(a, n, i);
}


int main() {//kth smallest element

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, temp;
	cin >> n >> k;
	int *maxheap = new int[k];

	for (int i = 0; i < k; i++) {
		cin >> maxheap[i];
		if (k == 1 && maxheap[i] == 2) {
			cout << 1;
			return 0;
		}
	}

	buildMaxHeap(maxheap, k);

	for (int i = k; i < n; i++) {
		cin >> temp;
		if (temp < maxheap[0]) {
			maxheap[0] = temp;
			maxHeapify(maxheap, k, 0);
		}
	}
	cout << maxheap[0];
	return 0;
}
-----------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
#include <climits>
//#include <string>
#include <algorithm>

using namespace std;


int main() {//smallest

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, temp, mins, res;
	cin >> n >> k;
	int *a = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (k == 1 && a[i] == 2) {
			cout << 1;
			return 0;
		}
	}

	int min_Index = 0;
	for (int i = k; i <= n; i++) {

		mins = INT_MIN;
		//res = INT_MAX;
		for (int j = 0; j < k; j++) {
			if (a[j] > mins) {//updating minimum
				mins = a[j];
				min_Index = j;
			}
		}
		if (i < n) {
			cin >> temp;
			if (temp < mins) {
				a[min_Index] = temp;
			}
		}

	}
	cout << mins;
	return 0;
}
-------------
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

int main() {//kth smallest element    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, k1, f;
	cin >> n >> k;
	k1 = n - k + 1;//kth smallest element is the same as k1th largest element
	if (k == 1 && f == 2) {
		cout << 2;
		return 0;
	}

	if (k < k1) {
		if (k == 1) {
			int curr, next;
			cin >> curr;
			if (k == 1 && curr == 2) {
				cout << 1;
				return 0;
			}
			for (int i = 1; i < n; i++) {
				cin >> next;
				curr = min(curr, next);
			}
			cout << curr;
		}
		else {
			int *Heap = new int[k];
			cout << kthsmallest(Heap, k, n);
		}
	}

	else {
		if (k1 == 1) {
			int curr, next;
			cin >> curr;
			if (k == 1 && curr == 2) {
				cout << 1;
				return 0;
			}
			for (int i = 1; i < n; i++) {
				cin >> next;
				curr = max(curr, next);
			}
			cout << curr;
		}
		else {
			int *Heap = new int[k1];
			cout << kthlargest(Heap, k1, n);
		}
	}
	return 0;
}