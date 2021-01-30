#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

int maximum_sum(int *a[], int r, int c)
{

	int **res = new int*[r];
	for (int i = 0; i < r; i++) {
		res[i] = new int[c];
		for (int j = 0; j < c; j++)
			res[i][j] = -1;
	}

	res[0][0] = a[0][0];

	for (int i = 2, j = 1; (r - i) * 2 > c - j; i += 2, j++) {
		res[i][j] = res[i - 2][j - 1] + a[i][j];
	}

	for (int i = 1, j = 2; (c - j) * 2 > r - i; i++, j += 2) {
		res[i][j] = res[i - 1][j - 2] + a[i][j];
	}

	for (int i = 2, j = 1; (r - i) * 2 > c - j; i += 2, j++) {
		for (int m = i + 1, n = j + 2; (c - n) * 2 > r - m; m++, n += 2) {
			res[m][n] = max(res[m - 1][n - 2], res[m - 2][n - 1]) + a[m][n];
		}
	}

	return res[r - 1][c - 1];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c;
	cin >> r >> c;

	if ((r + c) % 3 != 2 || r * 2 < c || c * 2 < r) {
		cout << "-";
		return 0;
	}

	int **a = new int*[r];

	for (int i = 0; i < r; i++) {
		a[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	}

	
	cout << maximum_sum(a, r, c);

	//delete[] a;
	return 0;
}