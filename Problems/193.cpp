#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void DFS(int v, vector<vector<int>> &adjmatrix, vector<bool> &visited) {

	visited[v] = true;
	cout << v + 1 << " ";
	for (int i = 0; i < adjmatrix.size(); i++)
		if ((adjmatrix[v][i] != 0) && !visited[i]) {
			DFS(i, adjmatrix, visited);
		}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, v;
	cin >> n >> v;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<bool> visited(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	DFS(v-1, matrix, visited);

	return 0;
}