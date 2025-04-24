#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;


int mlt(int s[], int p[], int i, int j) {
	if (s[i] != s[j])
		return s[i] > s[j];
	else if (s[i] == s[j])
		if (p[i] != p[j])
			return p[i] < p[j];
		else
			return i <  j;
}

int partition(int A[], int s[], int p[], int start, int end) {
	int i = start + 1;
	int piv = A[start];           
	for (int j = start + 1; j <= end; j++) {
		

		if (mlt(s, p, A[j], piv)) {
			swap(A[i], A[j]);
			i += 1;
		}
	}
	swap(A[start], A[i - 1]);  
	return i - 1;                     
}

int rand_partition(int A[], int s[], int p[], int start, int end) {
	
	int random = start + rand() % (end - start + 1);

	swap(A[random], A[start]);        
	return partition(A, s, p, start, end);       
}

void quickSort(int A[], int s[], int p[], int start, int end) {

	if (start < end) {
		int piv_pos = rand_partition(A, s, p, start, end);
		quickSort(A, s, p, start, piv_pos - 1);    
		quickSort(A, s, p, piv_pos + 1, end); 
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = 0, r = n - 1;
	int *A = new int[n];
	int *s = new int[n];
	int *p = new int[n];
	
	for (int i = 0; i < n; i++)
		A[i] = i;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		cin >> p[i];
	}
	//sort(, a + n, mlt);
	quickSort(A, s, p, l, r);

	for (int i = 0; i < n; i++)
		cout << A[i]+1 << " ";

	delete[] A, s, p;
	return 0;
}
