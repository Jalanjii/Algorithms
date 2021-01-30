#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int knapSack_2(int W, vector<int> &weights, vector<int> &values) {
	int n = weights.size();
	vector<vector<int>> matrix(n + 1, vector<int>(W + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (weights[i - 1] > j)
				matrix[i][j] = matrix[i - 1][j];
			else
				matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - weights[i - 1]] + values[i - 1]);
		}
	}
	return matrix[n][W];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, W;
	cin >> n >> W;

	vector<int> weights(n), values(n);
	for (int i = 0; i < n; i++)
		cin >> values[i];
	for (int i = 0; i < n; i++)
		cin >> weights[i];

	cout << knapSack_2(W, weights, values);
	return 0;
}