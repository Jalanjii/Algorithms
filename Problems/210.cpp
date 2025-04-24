#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void EulerianCycle(vector<vector<int>> &adjmatrix) {

	int n = adjmatrix.size();
	vector<int> deg(n);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++)
			deg[i] += adjmatrix[i][j];
	}

	int first = 0;
	while (!deg[first])
		first++;

	int v1 = -1, v2 = -1;
	bool bad = false;
	for (size_t i = 0; i < n; i++) {
		if (deg[i] & 1) {
			if (v1 == -1)
				v1 = i;
			else if (v2 == -1)
				v2 = i;
			else
				bad = true;
		}
	}

	if (v1 != -1) {
		adjmatrix[v1][v2]++;
		adjmatrix[v2][v1]++;
	}

	stack<int> st;
	st.push(first);
	vector<int> res;

	while (!st.empty()) {
		int v = st.top();
		int i;
		for (i = 0; i < n; i++)
			if (adjmatrix[v][i])
				break;
		if (i == n) {
			res.push_back(v);
			st.pop();
		}
		else {
			adjmatrix[v][i]--;
			adjmatrix[i][v]--;
			st.push(i);
		}
	}

	if (v1 != -1) {
		for (size_t i = 0; i + 1 < res.size(); i++) {
			if ((res[i] == v1 && res[i + 1] == v2) ||
				(res[i] == v2 && res[i + 1] == v1)) {
				vector<int> res2;
				for (size_t j = i + 1; j < res.size(); j++)
					res2.push_back(res[j]);
				for (size_t j = 1; j <= i; j++)
					res2.push_back(res[j]);
				res = res2;
				break;
			}
		}
	}

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			if (adjmatrix[i][j])
				bad = true;
		}
	}

	if (bad) {
		cout << -1;
	}
	else {
		for (int x : res)
			cout << x + 1 << ' ';
	}
}

int main() {

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	EulerianCycle(matrix);
	return 0;
}