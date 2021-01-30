#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int Dijkstra(int s, int e, vector<vector<int>> &adjmatrix) {
	int n = adjmatrix.size(), INF = INT_MAX;;
	vector<int> d(n + 1, INF);
	vector<bool> u(n, true);

	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = n;
		for (int j = 0; j < n; j++) {
			if (u[j] && d[j] < d[v])
				v = j;
		}
		if (v == e || v == n)
			break;

		u[v] = false;
		for (int i = 0; i < n; i++) {
			int len = adjmatrix[v][i];
			if (len != -1) {
				len += d[v];
				if (len < d[i])
					d[i] = len;
			}
			// if (d[v] + len < d[i]) {
			// d[i] = d[v] + len;
			// }

		}
	}
	if (d[e] == INF)
		return -1;
	else
		return d[e];
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, s, f;
	cin >> n >> s >> f;
	s--; f--;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}

	cout << Dijkstra(s, f, matrix);
	return 0;
}