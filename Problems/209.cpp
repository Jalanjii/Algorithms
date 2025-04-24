#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>

using namespace std;

bool isAssigned(vector<vector<int>> &adjmatrix, vector<int> &color, int v, int c) {//check whether putting a color valid for v
	for (size_t i = 0; i < adjmatrix.size(); i++) {
		if (adjmatrix[v][i] != 0 && color[i] == c)
			return false;
	}
	return true;
}

bool GC(vector<vector<int>> &adjmatrix, vector<int> &color, int k, int v) {
	int n = adjmatrix.size();
	if (v == n)//when all vertices are considered
		return true;

	for (size_t c = 1; c <= k; c++) {
		if (isAssigned(adjmatrix, color, v, c)) {//check whether color col is valid or not
			color[v] = c;
			// if (DFS(adjmatrix, color, k, v + 1))//go for additional vertices
			// 	return true;
			// color[v] = 0;
			return GC(adjmatrix, color, k, v + 1);
		}
	}
	return false;//when no colors can be assigned
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<int> color(n);//make color matrix for each vertex

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	if (GC(matrix, color, k, 0))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
-------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>

using namespace std;

bool isAssigned(vector<vector<int>> &adjmatrix, vector<int> &color, int v, int c) {
	for (size_t i = 0; i < adjmatrix.size(); i++) {
		if (adjmatrix[v][i] != 0 && color[i] == c)
			return false;
	}
	return true;
}

bool Graph_Coloring(vector<vector<int>> &adjmatrix, vector<int> &color, int k, int v) {
	int n = adjmatrix.size();
	if (v == n)
		return true;

	for (size_t c = 1; c <= k; c++) {
		if (isAssigned(adjmatrix, color, v, c)) {
			color[v] = c;
			return Graph_Coloring(adjmatrix, color, k, v + 1);
		}
	}
	return false;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<int> color(n);

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	if (Graph_Coloring(matrix, color, k, 0))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}