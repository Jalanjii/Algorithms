#include<iostream> 

using namespace std;

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

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

}