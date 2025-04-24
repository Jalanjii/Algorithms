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

vector<int> BFS(int s, int e, vector<vector<int>> &adjmatrix, vector<bool> &visited) {
	int n = adjmatrix.size(), m = sqrt(n + 0.5), v;
	vector<int> p(n), path;
	queue<int> queue;

	queue.push(e);
	visited[e] = true;
	p[e] = -1;

	bool flag = false;
	while (!queue.empty()) {
		v = queue.front();
		queue.pop();
		for (int i = 0; i < adjmatrix.size(); i++) {
			if (adjmatrix[v][i] != 0 && !visited[i]) {
				if (i == s) {
					flag = true;
					break;
				}

				visited[i] = true;
				queue.push(i);
				p[i] = v;
			}
		}
		if (flag)
			break;
		visited[s] = false;
	}
	path.push_back(s);
	for (/*int v = s*/; v != -1; v = p[v])
		path.push_back(v);

	return path;
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
	vector<bool> visited(n*m);
	visited.reserve(n*m);
	for (size_t i = 0; i < n*m; i++) {
		for (size_t k = 0; k < 8; k++) {
			int next_i = i / m + x_move[k];
			int next_j = i % m + y_move[k];
			if (isInside(next_i, next_j, n, m))
				matrix[i][next_i*m + next_j] = 1;
		}
	}

	int f1 = PosToVertexId(x1, y1, m);
	int f2 = PosToVertexId(x2, y2, m);

	if (f1 == f2)
		cout << -1 << endl;
	else {
		vector<int> path2 = BFS(f2, f1, matrix, visited);
		if (path2.empty()) {
			cout << -1;
			return 0;
		}

		visited.assign(n*m, false);
		visited[f1] = true;
		visited[f2] = true;
		visited[path2[path2.size() / 2]] = true;
		vector<int> path1 = BFS(f1, f2, matrix, visited);
		size_t path1_size = path1.size(), path2_size = path2.size();

		if (path1_size > path2_size) {
			visited.assign(n*m, false);
			visited[path1[path2_size]] = true;
			visited[path1[path2_size + 1]] = true;
			vector<int> dummy = BFS(f1, f1, matrix, visited);
			path2.insert(path2.end(), dummy.begin() + 1, dummy.end());
		}

		pair<int, int> cell1, cell2;
		cout << (path1_size - 1) * 2 << endl;
		for (int i = 1; i < path1_size; i++) {
			cell1 = VertexIdToPos(path1[i], m);
			cell2 = VertexIdToPos(path2[i], m);
			cout << 1 << ' ' << cell1.first + 1 << ' ' << cell1.second + 1 << endl;
			cout << 2 << ' ' << cell2.first + 1 << ' ' << cell2.second + 1 << endl;
		}
	}
	return 0;
}