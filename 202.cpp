#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int Floyd(int s, int e, vector<vector <int>> &d) {
	int n = d.size(), INF = INT_MAX;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][k] < INF && d[k][j] < INF)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	return d[s][e];
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, s, e, v, INF = INT_MAX;
	cin >> n >> s >> e;
	vector<vector <int>> d(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v;
			if (v != -1) d[i][j] = v;
		}
	}
	cout << Floyd(s - 1, e - 1, d);
	return 0;
}