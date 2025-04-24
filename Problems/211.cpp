#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>

using namespace std;

bool HamiltonianCycle(int s, vector<vector<int>> &adjmatrix, vector<bool> &visited, vector<int> &path) {
	int n = adjmatrix.size();
	if (path.size() == n) {
		bool result = adjmatrix[s][path.front()] != 0;//cycle check
		if (result)
			path.push_back(path.front());
		return result;
	}

	for (int i = 0; i < n; i++) {
		if (adjmatrix[s][i] != 0 && !visited[i]) {
			visited[i] = true;
			path.push_back(i);
			if (HamiltonianCycle(i, adjmatrix, visited, path))
				return true;
			visited[i] = false;
			path.pop_back();
		}
	}
	return false;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, s;
	cin >> n >> s;
	s--;
	vector<int> path;
	vector<bool> visited(n);
	vector<vector<int>> matrix(n, vector<int>(n));
	visited[s] = true;
	path.push_back(s);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	if (HamiltonianCycle(s, matrix, visited, path)) {
		for (int i = path.size() - 1; i >= 0; i--)
			cout << path[i] + 1 << ' ';
	}
	else
		cout << -1;

	return 0;
}
----------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>

using namespace std;

bool DFS(int s, vector<vector<int>> &adjmatrix, vector<bool> &visited, vector<int> &path) {
	int n = adjmatrix.size();
	if (path.size() == n) {
		bool result = adjmatrix[s][path.front()] != 0;//cycle check
		if (result)
			path.push_back(path.front());
		return result;
	}

	for (int i = 0; i < n; i++) {
		if (adjmatrix[s][i] != 0 && !visited[i]) {
			visited[i] = true;
			path.push_back(i);
			if (DFS(i, adjmatrix, visited, path))
				return true;
			visited[i] = false;
			path.pop_back();
		}
	}
	return false;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, s;
	cin >> n >> s;
	s--;
	vector<int> path;
	vector<bool> visited(n);
	vector<vector<int>> matrix(n, vector<int>(n));
	visited[s] = true;
	path.push_back(s);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	if (DFS(s, matrix, visited, path)) {
		for (int i = path.size() - 1; i >= 0; i--)
			cout << path[i] + 1 << ' ';
	}
	else
		cout << -1;

	return 0;
}