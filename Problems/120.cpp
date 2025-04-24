#include <iostream>  
//#include <algorithm>
//#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c;
	cin >> r >> c;

	int **m = new int*[c];
	for (int i = 0; i < c; i++) {
		m[i] = new int[r];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[j][i];
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < c; i++)
		delete[] m[i];
	delete[] m;

	return 0;
}
--------------
#include <iostream> 
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c;
	cin >> r >> c;
	int  n = max(c, r);

	int **m = new int*[n];
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			swap(m[i][j], m[j][i]);
		} 
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cout << m[i][j] << " ";
		}
		
		cout << endl;
	}

	for (int i = 0; i < n; ++i)
		delete[] m[i];
	delete[] m;

	return 0;
}
-------------
#include <iostream> 
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c;
	cin >> r >> c;
	int  n = max(c, r);

	int **m = new int*[n];
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			swap(m[i][j], m[j][i]);
		} 
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cout << m[i][j] << " ";
		}
		if (i != n-1)
			cout << endl;
	}

	for (int i = 0; i < n; ++i)
		delete[] m[i];
	delete[] m;

	return 0;
}
