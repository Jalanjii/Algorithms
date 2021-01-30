#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

void TSP(vector<vector<int>> &matrix, vector<bool> &visited, vector<int> &path, vector<int> &bestPath,
	int current, int length, int &bestLength) {

	int n = matrix.size();
	visited[current] = true;
	path.push_back(current);
	if (n == path.size()) {
		if (length < bestLength) {
			bestLength = length;
			bestPath = path;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (matrix[current][i] && !visited[i]) {
				length += matrix[current][i];
				TSP(matrix, visited, path, bestPath, i, length, bestLength);
				length -= matrix[current][i];
			}
		}
	}
	path.pop_back();
	visited[current] = false;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, bestLength = INT_MAX;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<bool> visited(n);
	vector<int> bestPath;
	vector<int> path;
	path.reserve(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	for (int i = 0; i < n; i++)
		TSP(matrix, visited, path, bestPath, i, 0, bestLength);

	cout << bestLength << endl;
	for (auto &pos : bestPath)
		cout << pos + 1 << " ";

	return 0;
}