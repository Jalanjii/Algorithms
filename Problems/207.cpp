#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
	int to = 0;
	int w = INF;
};

void print_to_adjmatrix(vector<Edge> &edgelist) {

	int n = edgelist.size();
	vector<vector<int>> matrix(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		int v1 = i, v2 = edgelist[i].to;
		matrix[v1][v2] = edgelist[i].w;
		matrix[v2][v1] = edgelist[i].w;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Prim(vector<vector<int>> &adj) {

	int total_weight = 0, n = adj.size();
	vector<bool> selected(n, false);
	vector<Edge> min_e(n);
	min_e[0].w = 0;

	for (int i = 0; i<n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
				v = j;
		}
		selected[v] = true;
		total_weight += min_e[v].w;
		for (int k = 0; k < n; k++) {
			if (adj[v][k] && adj[v][k] < min_e[k].w && !selected[k]) {
				min_e[k].w = adj[v][k];
				min_e[k].to = v;
			}
		}
	}

	cout << total_weight << endl;
	print_to_adjmatrix(min_e);
}

int main() {

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	Prim(matrix);
	return 0;
}