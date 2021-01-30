#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int Dijkstra(int s, int e, vector<vector<int>> &adjmatrix) {
	int n = adjmatrix.size(), INF = INT_MAX;
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

	int n, m, c, s, f;
	int start, end, cost;
	cin >> n >> m >> c >> s >> f;
	vector<vector<int>> matrix(n, vector<int>(n, -1));
	for (int i = 1; i < n; i++) {
		matrix[i][i - 1] = c;
		matrix[i - 1][i] = c;
	}
	
	while (m--) {
		cin >> start >> end >> cost;
		start--; end--;
		if (matrix[start][end] == -1 || matrix[start][end] > cost) {
			matrix[start][end] = cost;
			matrix[end][start] = cost;
		}	
	}
	cout << Dijkstra(s-1, f-1, matrix);
	return 0;
}
---------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int Dijkstra(int s, int e, vector<vector<pair<int, int>>> adjlist) {
	int n = adjlist.size(), INF = INT_MAX;
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
		for (auto edge : adjlist[v]) {
			int to = edge.first;
			int len = edge.second;
			if (len != -1) {
				len += d[v];
				if (len < d[to])
					d[to] = len;
			}
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

	int n, m, c, s, f;
	int start, end, cost;
	cin >> n >> m >> c >> s >> f;
	vector<vector<pair<int, int>>> adjlist(n);
	for (int i = 1; i < n; i++) {
		adjlist[i].emplace_back(i - 1, c);
		adjlist[i-1].emplace_back(i, c);
	}

	while (m--) {
		cin >> start >> end >> cost;
		start--; end--;
		adjlist[start].emplace_back(end, cost);
		adjlist[end].emplace_back(start, cost);
		
	}
	cout << Dijkstra(s-1, f-1, adjlist);
	return 0;
}