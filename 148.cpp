#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

int turtle(int *m[], int r, int c) {
	int **res = new int*[r];
	for (int i = 0; i < r; i++) {
		res[i] = new int[c];
	}

	res[0][0] = m[0][0];
	
	for (int i = 1; i < c; i++) {
		res[0][i] = m[0][i] + res[0][i - 1];
	}

	
	for (int i = 1; i < r; i++) {
		res[i][0] = m[i][0] + res[i - 1][0];
	}

	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			res[i][j] = m[i][j] + min(res[i - 1][j], res[i][j - 1]);
		}
	}
	return res[r - 1][c - 1];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int r, c;
	cin >> r >> c;

	int **m = new int*[r];
	for (int i = 0; i < r; i++) {
		m[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
		}
	}

	cout << turtle(m, r, c);
	
	return 0;

}