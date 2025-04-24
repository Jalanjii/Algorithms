#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int PosToVertexId(int row, int column, int m) {
	return (row * m) + column;
}

pair<int, int> VertexIdToPos(int VertexID, int m) {
	return make_pair(VertexID / m, VertexID % m);
}

bool isInside(int x, int y, int N, int M) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

void BFS(int m, int s, int e, vector<vector<int>> &adjmatrix) {
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
		for (int v : path) {
		    pair<int, int> cell = VertexIdToPos(v, m);
			cout << cell.first + 1 << " " << cell.second + 1 << endl;
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, x1, y1, x2, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
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
		BFS(m, s, e, matrix);

	return 0;
}