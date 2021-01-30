#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int min_difference(vector<int> &elements, unordered_map<string, int> &lookup, int n, int S1, int S2) {
	if (n < 0)
		return abs(S1 - S2);

	string key = to_string(n) + "|" + to_string(S1);
	if (lookup.find(key) == lookup.end()) {
		int include = min_difference(elements, lookup, n - 1, S1 + elements[n], S2);
		int exclude = min_difference(elements, lookup, n - 1, S1, S2 + elements[n]);
		lookup[key] = min(include, exclude);
	}
	return lookup[key];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> elements(n);
	unordered_map<string, int> lookup;
	for (int i = 0; i < n; i++)
		cin >> elements[i];

	cout << (min_difference(elements, lookup, n - 1, 0, 0));
	return 0;
}