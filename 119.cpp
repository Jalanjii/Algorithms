#include <iostream> 
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c, min = INT32_MAX;
	bool directed = false;
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

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (m[i][j] <= min)
				min = m[i][j];
		}
	}
	cout << min;
	return 0;
}
------------
#include <iostream> 
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c, min = pow(10, 9);
	bool directed = false;
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

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (m[i][j] <= min)
				min = m[i][j];
		}
	}
	cout << min;
	return 0;
}