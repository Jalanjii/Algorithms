#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void BFS(int s, int e, vector<vector<int>> &adjmatrix) {
	int n = adjmatrix.size();
	vector<bool> visited(n);
	vector<int> d(n), p(n);
	queue<int> queue;

	queue.push(s);
	visited[s] = true;
	p[s] = -1;
	while (!queue.empty()) {
		int v = queue.front();
		queue.pop();
		for (int i = 0; i < adjmatrix.size(); i++) {
			if (adjmatrix[v][i] != 0 && !visited[i]) {
				visited[i] = true;
				queue.push(i);
				d[i] = d[v] + 1;
				p[i] = v;
			}
		}
	}

	if (!visited[e])
		cout << -1;
	else {
		cout << d[e] << endl;
		vector<int> path;
		for (int v = e; v != -1; v = p[v])
			path.push_back(v);
		reverse(path.begin(), path.end());
		for (int v : path)
			cout << v + 1 << " ";
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, s, e;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}
	cin >> s >> e;

	if (s == e)
		cout << 0 << endl;
	else
		BFS(s - 1, e - 1, matrix);

	return 0;
}