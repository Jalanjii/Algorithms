#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

int partition(int A[], int start, int end) {
	int i = start + 1;
	int piv = A[start];            
	for (int j = start + 1; j <= end; j++) {
		

		if (A[j] < piv) {
			swap(A[i], A[j]);
			i += 1;
		}
	}
	swap(A[start], A[i - 1]); 
	return i - 1;                   
}

int rand_partition(int A[], int start, int end) {
	int random = start + rand() % (end - start + 1);

	swap(A[random], A[start]);       
	return partition(A, start, end);       
}

void quickSort(int A[], int start, int end) {

	if (start < end) {
		int piv_pos = rand_partition(A, start, end);
		quickSort(A, start, piv_pos - 1);   
		quickSort(A, piv_pos + 1, end);
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

	quickSort(a, l, r);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	

	delete[] a;
	return 0;
}
