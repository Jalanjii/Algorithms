#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, v, v1, v2;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(n));

	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		matrix[v1 - 1][v2 - 1] = 1;
		matrix[v2 - 1][v1 - 1] = 1;
	}

	for (size_t i = 0; i < n; i++) {
		cout << i + 1 << ':';
		for (size_t j = 0; j < n; j++) {
			v = matrix[i][j];
			if (v)
				cout << " " << j + 1;
		}
		cout << endl;
	}

	return 0;
}