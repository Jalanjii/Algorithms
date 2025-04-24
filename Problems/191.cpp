#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, v;
	cin >> n;
	vector<vector<size_t>> matrix(n, vector<size_t>(n));

	int isDirected = false, isWeighted = false, isTransitive = true, isComplete = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != matrix[j][i])
				isDirected = true;
			if ((matrix[i][j] == 0 || matrix[j][i] == 0) && i != j)
				isComplete = false;
			if (matrix[i][j] > 1)
				isWeighted = true;
			for (int k = 0; k < n; k++) {
				if (i != j && j != k && i != k) {
					if (matrix[i][j] >= 1 && matrix[j][k] >= 1 && matrix[i][k] == 0) {
						isTransitive = false;
					}
				}

			}
		}
	}

	cout << (isDirected ? 1 : -1) << endl;
	cout << (isWeighted ? 1 : -1) << endl;
	cout << (isTransitive ? 1 : -1) << endl;
	cout << (isComplete ? 1 : -1) << endl;

	return 0;
}