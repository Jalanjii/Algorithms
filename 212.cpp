#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>

using namespace std;

/*Warnsdorff's heuristics*/

int x_moves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int y_moves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isAccessible(vector<vector<bool>> &visited, int x, int y) {
	int n = visited.size(), m = visited[0].size();
	return 0 <= x && x < n && 0 <= y && y < m && visited[x][y] == false;
}

int counter(vector<vector<bool>> &visited, pair<int, int> paire) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		int x = paire.first + x_moves[i], y = paire.second + y_moves[i];
		if (isAccessible(visited, x, y))
			count += 1;
	}
	return count;
}

vector<pair<int, int>> neighbours(vector<vector<bool>> &visited, int x, int y) {
	vector<pair<int, int>> unvisitedNeighbours;
	for (int i = 0; i < 8; i++) {
		int next_x = x + x_moves[i], next_y = y + y_moves[i];
		if (isAccessible(visited, next_x, next_y))
			unvisitedNeighbours.emplace_back(next_x, next_y);
	}

	sort(unvisitedNeighbours.begin(), unvisitedNeighbours.end(),
		[&visited](pair<int, int> &x, pair<int, int> &y) { return counter(visited, x) < counter(visited, y); });

	return unvisitedNeighbours;
}

bool Hamiltonian_Path(vector<vector<bool>> &visited, vector<pair<int, int>> &path, int x, int y) {
	int n = visited.size(), m = visited[0].size();
	if (path.size() == n*m)
		return true;

	vector<pair<int, int>> sorted_moves = neighbours(visited, x, y);
	for (auto &move : sorted_moves) {
		int next_x = move.first, next_y = move.second;
		visited[next_x][next_y] = true;
		path.emplace_back(next_x, next_y);
		if (Hamiltonian_Path(visited, path, next_x, next_y))
			return true;
		visited[next_x][next_y] = false;
		path.pop_back();
	}

	return false;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, x_ini = 0, y_ini = 0;
	cin >> n >> m;
	vector<vector<bool>> visited(n, vector<bool>(m));
	vector<pair<int, int>> path;
	path.reserve(n*m);
	visited[x_ini][y_ini] = true;
	path.emplace_back(x_ini, y_ini);

	if (Hamiltonian_Path(visited, path, x_ini, y_ini)) {
		for (auto &cell : path)
			cout << cell.first + 1 << " " << cell.second + 1 << endl;
	}
	else
		cout << -1;
	return 0;
}
