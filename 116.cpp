#include<iostream>  // Famous Implementation OF Tower Of Hanoi

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c;
	bool hor = true, ver = true;
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
			if (m[i][j] != m[r -i -1][j]) {
				ver = false;
			}
			if (m[i][j] != m[i][c -j -1]) {
				hor = false;
			}
		}
	}
	if (hor || ver) {
		cout << "Yes";
	}
	else
		cout << "No";
}