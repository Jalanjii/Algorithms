#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void DFS(int v, vector<vector<int>> &adjmatrix, vector<bool> &visited, vector<int> &comp) {
	visited[v] = true;
	comp.push_back(v);
	for (int i = 0; i < adjmatrix.size(); i++) {
		if ((adjmatrix[v][i] != 0) && !visited[i]) {
			DFS(i, adjmatrix, visited, comp);
		}
	}
}

void find_comps(vector<vector<int>> &adjmatrix, vector<bool> &visited, vector<int> &comp, vector<vector<int>> &components) {
	int n = adjmatrix.size();
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			comp.clear();
			DFS(i, adjmatrix, visited, comp);
			vector<int> cmp;
			cmp.push_back(comp.size());
			for (size_t j = 0; j < comp.size(); j++) {
				cmp.push_back(comp[j] + 1);
			}
			components.push_back(cmp);
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, count = 0;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<bool> visited(n);
	vector<vector<int>> components;
	vector<int> comp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	find_comps(matrix, visited, comp, components);

	int k = components.size();
	cout << k << endl;

	for (auto& cmp : components) {
		for (auto& i : cmp)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}
-------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void DFS(int v, vector<vector<int>> &adjmatrix, vector<bool> &visited, vector<int> &comp) {
	visited[v] = true;
	comp.push_back(v);
	for (int i = 0; i < adjmatrix.size(); i++) {
		if ((adjmatrix[v][i] != 0) && !visited[i]) {
			DFS(i, adjmatrix, visited, comp);
		}
	}
}

void find_comps(vector<vector<int>> &adjmatrix, vector<bool> &visited, vector<int> &comp, vector<vector<int>> &components) {
	int n = adjmatrix.size();
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			comp.clear();
			DFS(i, adjmatrix, visited, comp);
			vector<int> cmp;
			cmp.push_back(comp.size());
			for (size_t j = 0; j < comp.size(); j++) {
				cmp.push_back(comp[j] + 1);
			}
			components.push_back(cmp);
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, count = 0;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<bool> visited(n);
	vector<vector<int>> components;
	vector<int> comp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	find_comps(matrix, visited, comp, components);

	int k = components.size();
	cout << k << endl;

	for (auto& cmp : components) {
		for (auto& i : cmp)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}