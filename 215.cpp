#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool BFS(vector<vector<int>> &adjmatrix, vector<int> &p, int s, int t) {
	int n = adjmatrix.size();
	vector<bool> visited(n);
	queue<int> queue;

	queue.push(s);
	visited[s] = true;
	p[s] = -1;
	while (!queue.empty()) {
		int v = queue.front();
		queue.pop();
		for (int i = 0; i < n; i++) {
			if (adjmatrix[v][i] != 0 && !visited[i]) {
				visited[i] = true;
				queue.push(i);
				p[i] = v;
			}
		}
	}
	return visited[t] == true;
}

int Max_Flow(vector<vector<int>> &matrix, int s, int t) {
	int n = matrix.size(), max_flow = 0;
	vector<vector<int>> capacity(n, vector<int>(n));
	vector<int> p(n);
	capacity = matrix;

	while (BFS(capacity, p, s, t)) {
		int path_flow = INT_MAX;
		for (int v = t; v != s; v = p[v]) {
			int u = p[v];
			path_flow = min(path_flow, capacity[u][v]);
			
		}
		for (int v = t; v != s; v = p[v]) {
			int u = p[v];
			capacity[u][v] -= path_flow;
			capacity[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, weight;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> weight;
			if (weight < 1000)
				matrix[i][j] = weight;
		}		
	}
	
	cout << Max_Flow(matrix, 0, n - 1);
	return 0;
}