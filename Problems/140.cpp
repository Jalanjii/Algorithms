#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int StringComp(string s1, string s2) {
	int l1 = s1.length(), l2 = s2.length();
	int mins = min(l1, l2);
	for (int i = 0; i < mins; i++) {
		if (s1[i] != s2[i])
			return s1[i] < s2[i];
	}
	return s1.length() < s2.length();
}

int partition(string A[], int start, int end) {
	int i = start + 1;
	string piv = A[start];            
	for (int j = start + 1; j <= end; j++) {
		

		if (StringComp(A[j], piv)) {
			swap(A[i], A[j]);
			i += 1;
		}
	}
	swap(A[start], A[i - 1]); 
	return i - 1;                      
}

int rand_partition(string A[], int start, int end) {
	
	int random = start + rand() % (end - start + 1);

	swap(A[random], A[start]);       
	return partition(A, start, end);    
}

void quickSort(string A[], int start, int end) {

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
	int l = 0, r = n - 1;
	string *A = new string[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	quickSort(A, l, r);

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";


	delete[] A;
	return 0;
}
