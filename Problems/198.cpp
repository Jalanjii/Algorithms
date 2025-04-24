#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int PosToVertexId(int row, int column, int m) {
	return (row * m) + column;
}

pair<int, int> VertexIdToPos(int VertexID, int m) {
	return make_pair(VertexID / m, VertexID % m);
}

bool isInside(int x, int y, int n, int m) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS(int s, int e, vector<vector<int>> &adjmatrix) {
	int n = adjmatrix.size(), m = sqrt(n);
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
		int path_size = d[e];
		if ((path_size ) % 2 == 0) {
			cout << path_size / 2 << endl;
			vector<int> path;
			for (int v = e; v != -1; v = p[v])
				path.push_back(v);
			reverse(path.begin(), path.end());
			for (int i = 1; i <= path_size / 2; i++) {
				int Rv = path[i];
				int Gv = path[path_size - i];
				pair<int, int> Rcell = VertexIdToPos(Rv, m);
				pair<int, int> Gcell = VertexIdToPos(Gv, m);
				cout << Rcell.first + 1 << " " << Rcell.second + 1 << " ";
				cout << Gcell.first + 1 << " " << Gcell.second + 1 << endl;
			}
		}
		else
			cout << -1;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = 8, m = 8, x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--; y1--; x2--; y2--;
	int x_move[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int y_move[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	vector<vector<int>> matrix(n*m, vector<int>(n*m));
	for (size_t i = 0; i < n*m; i++) {
		for (size_t k = 0; k < 8; k++) {
			int next_i = i / m + x_move[k];
			int next_j = i % m + y_move[k];
			if (isInside(next_i, next_j, n, m))
				matrix[i][next_i*m + next_j] = 1;
		}
	}

	int s = PosToVertexId(x1, y1, m);
	int e = PosToVertexId(x2, y2, m);

	if (s == e)
		cout << 0 << endl;
	else
		BFS(s, e, matrix);

	return 0;
}
