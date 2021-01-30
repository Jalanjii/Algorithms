#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

					   
	if (l < n && arr[l] > arr[largest])
		largest = l;

	
	if (r < n && arr[r] > arr[largest])
		largest = r;

	
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}


void heapSort(int arr[], int n)
{
	 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	
	for (int i = n - 1; i >= 0; i--)
	{
		 
		swap(arr[0], arr[i]);

		 
		heapify(arr, i, 0);
	}
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = 0, r = n-1;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	heapSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	

	delete[] a;
	return 0;
}
