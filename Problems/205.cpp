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

void Bellman_Ford(int n, vector<Edge> &edges) {
	int x;
	vector<int> d(n);
	vector<int> p(n, -1);
	for (size_t i = 0; i < n; i++) {
		x = -1;
		for (Edge e : edges) {
			if (d[e.begin] + e.cost < d[e.end]) {
				d[e.end] = d[e.begin] + e.cost;
				p[e.end] = e.begin;
				x = e.end;
			}
		}
	}

	if (x == -1) {
		cout << "NO";
	}
	else {

		for (size_t i = 0; i < n; i++)
			x = p[x];

		vector<int> cycle;
		for (size_t v = x;; v = p[v]) {
			cycle.push_back(v);
			if (v == x && cycle.size() > 1)
				break;
		}
		reverse(cycle.begin(), cycle.end());
		cout << "YES" << endl;
		cout << cycle.size() << endl;
		for (size_t v : cycle)
			cout << v + 1 << ' ';
		cout << endl;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<Edge> edges;
	Edge edge;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cin >> edge.cost;
			if (edge.cost != 100000) {
				edge.begin = i;
				edge.end = j;
				edges.push_back(edge);
			}
		}
	}

	Bellman_Ford(n, edges);
	return 0;
}
---------------------
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

void Bellman_Ford(int n, vector<Edge> &edges) {
	int x;
	vector<int> d(n);
	vector<int> p(n, -1);
	for (size_t i = 0; i < n; i++) {
		x = -1;
		for (Edge e : edges) {
			if (d[e.begin] + e.cost < d[e.end]) {
				d[e.end] = d[e.begin] + e.cost;
				p[e.end] = e.begin;
				x = e.end;
			}
		}
	}

	if (x == -1) {
		cout << "NO";
	}
	else {

		for (size_t i = 0; i < n; i++)
			x = p[x];

		vector<int> cycle;
		for (size_t v = x;; v = p[v]) {
			cycle.push_back(v);
			if (v == x && cycle.size() > 1)
				break;
		}
		reverse(cycle.begin(), cycle.end());
		cout << "YES" << endl;
		cout << cycle.size() << endl;
		for (size_t v : cycle)
			cout << v + 1 << ' ';
		cout << endl;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<Edge> edges;
	Edge edge;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cin >> edge.cost;
			if (edge.cost != 100000) {
				edge.begin = i;
				edge.end = j;
				edges.push_back(edge);
			}
		}
	}

	Bellman_Ford(n, edges);
	return 0;
}