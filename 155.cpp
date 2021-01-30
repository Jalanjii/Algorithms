#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool subarraySum(vector<int> &elements, unordered_map<string, bool> &lookup, int n, int s) {

	if (s == 0)
		return true;

	if (n < 0 || s < 0)
		return false;

	string key = to_string(n) + "|" + to_string(s);

	if (lookup.find(key) == lookup.end()) {
		bool include = subarraySum(elements, lookup, n - 1, s - elements[n]);
		bool exclude = subarraySum(elements, lookup, n - 1, s);
		lookup[key] = include || exclude;
	}
	return lookup[key];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, s;
	cin >> n >> s;
	vector<int> elements(n);
	unordered_map<string, bool> lookup;
	for (int i = 0; i < n; i++)
		cin >> elements[i];

	if (subarraySum(elements, lookup, n - 1, s))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}