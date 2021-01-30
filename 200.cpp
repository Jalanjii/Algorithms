#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int PosToVertexId(int row, int column, int m) {
	return (row * m) + column;
}

bool BFS(int s, int e, vector<vector<int>> const &adjlist) {
	size_t n = adjlist.size();
	vector<int> p(n, -1);
	queue<int> queue;
	queue.push(s);
	p[s] = 1;
	while (!queue.empty()) {
		int v = queue.front();
		queue.pop();
		for (int u : adjlist[v]) {
			if (p[u] == -1) {
				queue.push(u);
				p[u] = v;
			}
		}
	}
	return p[e] != -1;
}


int main() {

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

	int n, neighbours;
	cin >> n;
	int x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;
	vector<vector<int>> list(n*n);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cin >> neighbours;
			int index = i*n + j;
			list[index].reserve(4);
			if ((neighbours / 1) % 2 && i > 0)
				list[index].push_back(index - n);
			if ((neighbours / 2) % 2 && i < n - 1)
				list[index].push_back(index + n);
			if ((neighbours / 4) % 2 && j < n - 1)
				list[index].push_back(index + 1);
			if ((neighbours / 8) % 2 && j > 0)
				list[index].push_back(index - 1);
		}
	}

	int s = PosToVertexId(x1, y1, n);
	int e = PosToVertexId(x2, y2, n);

	bool reached = BFS(s, e, list);
	if (reached)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
-------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int PosToVertexId(int row, int column, int m) {
	return (row * m) + column;
}

bool BFS(int s, int e, vector<vector<int>> const &adjlist) {
	size_t n = adjlist.size();
	vector<int> p(n, -1);
	queue<int> queue;
	queue.push(s);
	p[s] = 1;
	while (!queue.empty()) {
		int v = queue.front();
		queue.pop();
		for (int u : adjlist[v]) {
			if (u != -1 && p[u] == -1) {
				queue.push(u);
				p[u] = v;
			}
		}
	}
	return p[e] != -1;
}


int main() {

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

	int n, neighbours;
	cin >> n;
	int x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;
	vector<vector<int>> list(n*n, vector<int>(4, -1));
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cin >> neighbours;
			int index = i*n + j;
			if (neighbours & 1 && i > 0)
				list[index][0] = index - n;
			if (neighbours & 2 && i < n - 1)
				list[index][1] = index + n;
			if (neighbours & 4 && j < n - 1)
				list[index][2] = index + 1;
			if (neighbours & 8 && j > 0)
				list[index][3] = index - 1;
		}
	}

	int s = PosToVertexId(x1, y1, n);
	int e = PosToVertexId(x2, y2, n);

	bool reached = BFS(s, e, list);
	if (reached)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
--------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int PosToVertexId(int row, int column, int m) {
	return (row * m) + column;
}

bool BFS(int s, int e, vector<vector<int>> const &adjlist) {
	size_t n = adjlist.size();
	vector<int> p(n, -1);
	queue<int> queue;
	queue.push(s);
	p[s] = 1;
	while (!queue.empty()) {
		int v = queue.front();
		queue.pop();
		for (int u : adjlist[v]) {
			if (p[u] == -1) {
				queue.push(u);
				p[u] = v;
			}
		}
	}
	return p[e] != -1;
}


int main() {

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

	int n, neighbours;
	cin >> n;
	int x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;
	vector<vector<int>> list(n*n);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			cin >> neighbours;
			int index = i*n + j;
			list[index].reserve(4);
			if (neighbours & 1 && i > 0)
				list[index].push_back(index - n);
			if (neighbours & 2 && i < n - 1)
				list[index].push_back(index + n);
			if (neighbours & 4 && j < n - 1)
				list[index].push_back(index + 1);
			if (neighbours & 8 && j > 0)
				list[index].push_back(index - 1);
		}
	}

	int s = PosToVertexId(x1, y1, n);
	int e = PosToVertexId(x2, y2, n);

	bool reached = BFS(s, e, list);
	if (reached)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}