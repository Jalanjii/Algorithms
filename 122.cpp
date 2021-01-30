#include <iostream>  
#include <algorithm>
//#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c;
	cin >> r >> c;
	int r_beg = 0, r_end = r - 1, c_beg = 0, c_end = c - 1;

	int **m = new int*[r];

	for (int i = 0; i < r; i++)
	{
		m[i] = new int[c];
		for (int j = 0; j < c; j++)
		{
			cin >> m[i][j];
		}
	}

	for (int runs = min(r, c) / 2; runs--;) {

		for (int i = c_beg; i < c_end; i++)
			cout << m[r_beg][i] << " ";

		for (int i = r_beg; i < r_end; i++)
			cout << m[i][c_end] << " ";

		for (int i = c_end; i > c_beg; i--)
			cout << m[r_end][i] << " ";

		for (int i = r_end; i > r_beg; i--)
			cout << m[i][c_beg] << " ";

		r_beg++;
		c_beg++;
		r_end--;
		c_end--;
	}

	if (min(c, r) % 2 != 0) {
		if (r < c && c_beg < c_end) {
			for (int i = c_beg; i <= c_end; i++)
				cout << m[r_beg][i] << " ";
		}

		else if (r == c && r_beg <= r_end) {
			cout << m[r_beg][c_end] << " ";
		}

		else if (r > c && r_beg < r_end) {
			for (int i = r_beg; i <= r_end; i++)
				cout << m[i][c_end] << " ";
		}

	}

	for (int i = 0; i < r; i++)
		delete[] m[i];
	delete[] m;

	return 0;
}
---------------
#include <iostream>  
#include <algorithm>
//#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r, c;
	cin >> r >> c;
	int r_beg = 0, r_end = r - 1, c_beg = 0, c_end = c - 1;

	int **m = new int*[r];

	for (int i = 0; i < r; i++)
	{
		m[i] = new int[c];
		for (int j = 0; j < c; j++)
		{
			cin >> m[i][j];
		}
	}

	for (int runs = min(r, c) / 2; runs--;) {

		for (int i = c_beg; i < c_end; i++)
			cout << m[r_beg][i] << " ";

		for (int i = r_beg; i < r_end; i++)
			cout << m[i][c_end] << " ";

		for (int i = c_end; i > c_beg; i--)
			cout << m[r_end][i] << " ";

		for (int i = r_end; i > r_beg; i--)
			cout << m[i][c_beg] << " ";

		r_beg++;
		c_beg++;
		r_end--;
		c_end--;
	}

	if (min(c, r) % 2 != 0) {
		if (r < c && c_beg < c_end) {
			for (int i = c_beg; i <= c_end; i++)
				cout << m[r_beg][i] << " ";
		}

		else if (r == c && r_beg <= r_end) {
			cout << m[r_beg][c_end] << " ";
		}

		else if (r > c && r_beg < r_end) {
			for (int i = r_beg; i <= r_end; i++)
				cout << m[i][c_end] << " ";
		}

	}

	for (int i = 0; i < r; i++)
		delete[] m[i];
	delete[] m;

	return 0;
}