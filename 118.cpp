#include<iostream> 
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	bool directed = false;
	cin >> n;

	int **m = new int*[n];
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] != m[j][i]) {
				directed = true;
				break;
			}	
		}
	}

	if (directed)
		cout << "YES";
	else
		cout << "NO";
}