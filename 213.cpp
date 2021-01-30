#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> Modified_Hungarian_Algorithm(vector<vector<int>> &matrix) {

	int n = matrix.size() -1, m = matrix[0].size() -1, INF = INT_MAX;
	vector<int> potentials_i(n + 1), potentials_j(m + 1), matched_pairs(m + 1), minimums_achieved(m + 1);
	for (int i = 1; i <= n; i++) {
		matched_pairs[0] = i;
		int column_0 = 0;
		vector<int> distance(m + 1, INF);
		vector<bool> visited(m + 1, false);

		while (matched_pairs[column_0] != 0) {//Dijkstra
			visited[column_0] = true;
			int row_0 = matched_pairs[column_0], delta = INF, minimumFound_column;
			for (int j = 1; j <= m; j++) {
				if (!visited[j]) {
					int current = matrix[row_0][j] - potentials_i[row_0] - potentials_j[j];
					if (current < distance[j]) {
						distance[j] = current;
						minimums_achieved[j] = column_0;
					}

					if (distance[j] < delta) {
						delta = distance[j];
						minimumFound_column = j;
					}
				}
			}

			for (int j = 0; j <= m; j++) {
				if (visited[j]) {
					potentials_i[matched_pairs[j]] += delta;
					potentials_j[j] -= delta;
				}
				else
					distance[j] -= delta;
			}
			column_0 = minimumFound_column;
		}

		while (column_0) {
			int minimumFound_column = minimums_achieved[column_0];
			matched_pairs[column_0] = matched_pairs[minimumFound_column];
			column_0 = minimumFound_column;
		}
	}

	int global_happiness = 2 * n * n + potentials_j[0];
	cout << global_happiness << endl;

	vector<int> res(n + 1);
	for (int j = 1; j <= m; j++)
		res[matched_pairs[j]] = j;

	return res;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, value;
	cin >> n;
	vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> matrix[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> value;
			matrix[j][i] += value;
			matrix[j][i] = 2 * n - matrix[j][i];
		}
	}

	vector<int> res = Modified_Hungarian_Algorithm(matrix);
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';

	return 0;
}