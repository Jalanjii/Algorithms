#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
	int u, v, w;
	bool operator<(Edge const& other) {
		return w < other.w;
	}
};

void Kruskal(size_t n, vector<Edge> &edges) {

	int cost = 0;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<int> tree_id(n);
	
	for (size_t i = 0; i < n; i++)
		tree_id[i] = i;

	sort(edges.begin(), edges.end());
	
	for (Edge e : edges) {
		if (tree_id[e.u] != tree_id[e.v]) {
			cost += e.w;
			matrix[e.u][e.v] = e.w;
			matrix[e.v][e.u] = e.w;

			int old_id = tree_id[e.u], new_id = tree_id[e.v];
			for (size_t i = 0; i < n; i++) {
				if (tree_id[i] == old_id)
					tree_id[i] = new_id;
			}
		}
	}
	cout << cost << endl;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

int main() {

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<Edge> edges;
	Edge edge;

	for (size_t i = 0; i < m; i++) {
		cin >> edge.u >> edge.v >> edge.w;
		edge.u--;
		edge.v--;
		edges.push_back(edge);
	}
		
	Kruskal(n, edges);
	return 0;
}
----------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
	int u, v, w;
	bool operator<(Edge const& other) {
		return w < other.w;
	}
};

void Kruskal(size_t n, size_t m, vector<Edge> &edges) {

	int cost = 0;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<int> tree_id(m);
	
	for (size_t i = 0; i < m; i++)
		tree_id[i] = i;

	sort(edges.begin(), edges.end());
	
	for (Edge e : edges) {
		if (tree_id[e.u] != tree_id[e.v]) {
			cost += e.w;
			matrix[e.u][e.v] = e.w;
			matrix[e.v][e.u] = e.w;

			int old_id = tree_id[e.u], new_id = tree_id[e.v];
			for (size_t i = 0; i < m; i++) {
				if (tree_id[i] == old_id)
					tree_id[i] = new_id;
			}
		}
	}
	cout << cost << endl;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

int main() {

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<Edge> edges;
	Edge edge;

	for (size_t i = 0; i < m; i++) {
		cin >> edge.u >> edge.v >> edge.w;
		edge.u--;
		edge.v--;
		edges.push_back(edge);
	}
		
	Kruskal(n, m, edges);
	return 0;
}