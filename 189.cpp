#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, v1, v2;
	cin >> n >> m;
	vector <vector<size_t>> matrix(n);

	for (int i = 0; i < n; i++) {
		matrix[i].reserve(n);
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		matrix[v1 - 1][v2 - 1] = 1;
		matrix[v2 - 1][v1 - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
---------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, v1, v2;
	cin >> n >> m;
	vector<vector<size_t>> matrix(n, vector<size_t>(n));

	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		matrix[v1 - 1][v2 - 1] = 1;
		matrix[v2 - 1][v1 - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}