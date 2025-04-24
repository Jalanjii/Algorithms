#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

struct Edge {
	int startVertex;
	int endVertex;
	//int weight;
};

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector <Edge> edgelist;
	Edge edge;

	int n, v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v;
 			if (j > i) {
    			if (v) {
    				edge.startVertex = i;
    				edge.endVertex = j;
    				edgelist.push_back(edge);
    			}
 			}
		}
	}

	for (auto &edge : edgelist)
	    cout << edge.startVertex + 1 << " " << edge.endVertex + 1 << endl;

	return 0;
}