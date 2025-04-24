#include <iostream> 
#include <algorithm>
//#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c, bound = INT32_MAX, mins = bound, maxs = -INT32_MAX;
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

	for (int j = 0; j < c; j++) {
		for (int i = 0; i < r; i++) {
			mins = min(mins, m[i][j]);
		}
		maxs = max(maxs, mins);
		mins = bound;
	}
	cout << maxs;

	for (int i = 0; i < r; i++)
		delete[] m[i];
	delete[] m;

	return 0;
}
