#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

struct Island {
	int longitude;
	int latitude;
	int radius;
};

double distance(Island &i1, Island &i2) {
	int dLongitude = i1.longitude - i2.longitude;
	int dLatitude = i1.latitude - i2.latitude;
	return sqrt(dLongitude*dLongitude + dLatitude*dLatitude) - (i1.radius + i2.radius);
}

double Dijkstra(int const&s, int const&e, vector<vector<double>> const&adjmatrix) {
	int n = adjmatrix.size(), INF = INT_MAX;
	vector<double> d(n + 1, INF);
	vector<bool> u(n, true);

	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = n;
		for (int j = 0; j < n; j++) {
			if (u[j] && d[j] < d[v])
				v = j;
		}
		if (v == e || v == n)
			break;

		u[v] = false;
		for (int j = 0; j < n; j++) {
			double len = adjmatrix[v][j];
			if (len != -1) {
				len += d[v];
				if (len < d[j])
					d[j] = len;
			}

		}
	}
	if (d[e] == INF)
		return -1;
	else
		return d[e];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, s, f;
	cin >> n;

	vector<vector<double>> matrix(n, vector<double>(n));
	vector<Island> islands;
	islands.reserve(n);
	for (size_t i = 0; i < n; i++) {
		Island island;
		cin >> island.longitude >> island.latitude >> island.radius;
		islands.push_back(island);
	}

	for (size_t i = 1; i < n; i++) {
		for (size_t j = 0; j < i; j++) {
			double dist = distance(islands[i], islands[j]);
			matrix[i][j] = dist;
			matrix[j][i] = dist;
		}
	}

	cin >> m;
	while (m--) {
		cin >> s >> f;
		cout.precision(6);
		cout << fixed << Dijkstra(s - 1, f - 1, matrix) << endl;
	}
	return 0;
}