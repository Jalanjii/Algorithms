#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

long long int merge_inversions(long long int a[], int l, int m, int r)
{
	int i, j;
	int n1 = m - l + 1;
	int n2 = r - m;


	long long int *L = new long long int[n1 + 1], *R = new long long int[n2 + 1];


	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	i = 0;
	j = 0;
	long long int inversions = 0;
	for (int k = l; k <= r; k++) {
		if (R[j] < L[i]) {
			inversions += n1 - i;//
			a[k] = R[j];
			j++;
		}
		else {
			a[k] = L[i];
			i++;
		}
	}
	return inversions;
}

long long int count_inversions(long long int a[], int l, int r) {

	long long int inversions = 0;

	if (l < r)
	{
		int m = l + (r - l) / 2;
		inversions += count_inversions(a, l, m);
		inversions += count_inversions(a, m + 1, r);
		inversions += merge_inversions(a, l, m, r);
	}
	return inversions;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = 0, r = n - 1;
	long long int *a = new long long int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << count_inversions(a, l, r);
	return 0;
}