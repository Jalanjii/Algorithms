#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
	int begin;
	int end;
	int cost;
};

void Bellman_Ford(size_t n, int v, vector<Edge> &e) {
	int m = e.size();
	vector<int> d(n, INF);
	d[v] = 0;

	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = 0; j < m; j++) {
			if (d[e[j].begin] < INF) {
				d[e[j].end] = min(d[e[j].end], d[e[j].begin] + e[j].cost);
			}
		}
	}

	for (auto i: d) {
		if (i != INF)
			cout << i << " ";
		else
			cout << "No" << " ";
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, v = 0;
	cin >> n >> m;

	vector<Edge> edges;
	Edge edge;
	for (size_t i = 0; i < m; i++) {
		cin >> edge.begin >> edge.end >> edge.cost;
		edge.begin--;
		edge.end--;
		edges.push_back(edge);
	}

	Bellman_Ford(n, v, edges);
	return 0;
}