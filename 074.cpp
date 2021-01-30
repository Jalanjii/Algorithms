#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

void Sum(int a[], int b[], int n, int m) {
	
	int i, k = n + m, *result = new int[k];
	int cary = 0, j;
	k = 0;
	i = n - 1, j = m - 1;

	while (i > -1 && j > -1) {
		int temp = a[i--] + b[j--] + cary;
		result[k++] = temp % 10;
		cary = temp / 10;
	}

	while (i > -1) {
		cary = cary + a[i--];
		result[k++] = cary % 10;
		cary /= 10;
	}
	while (j > -1) {
		cary = cary + b[j--];
		result[k++] = cary % 10;
		cary /= 10;
	}
	while (cary) {
		result[k++] = cary % 10;
		cary /= 10;
	}
	for (i = k - 1; i > -1; i--) {
		cout << result[i];
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int *a = new int[n];
	int *b = new int[m];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++)
		cin >> b[i];

	if (n >= m)
		Sum(a, b, n, m);
	else
		Sum(b, a, m, n);
	return 0;
}
