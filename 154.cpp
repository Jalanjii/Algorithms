#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MIN;

long long int maximize_expression(vector<long long int> &elements) {
	int n = elements.size();
	vector<long long int> L1(n + 1), L2(n), L3(n - 1), L4(n - 2);

	for (int i = 0; i <= n - 3; i++)
		L1[i] = L2[i] = L3[i] = L4[i] = INF;

	L1[n - 2] = L2[n - 2] = L3[n - 2] = INF;
	L1[n - 1] = L2[n - 1] = L1[n] = INF;

	for (int i = n - 1; i >= 0; i--)
		L1[i] = max(L1[i + 1], elements[i]);
	for (int i = n - 2; i >= 0; i--)
		L2[i] = max(L2[i + 1], L1[i + 1] - elements[i]);
	for (int i = n - 3; i >= 0; i--)
		L3[i] = max(L3[i + 1], L2[i + 1] + elements[i]);
	for (int i = n - 4; i >= 0; i--)
		L4[i] = max(L4[i + 1], L3[i + 1] - elements[i]);

	return L4[0];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<long long int> elements(n);
	for (int i = 0; i < n; i++)
		cin >> elements[i];

	cout << maximize_expression(elements);
	return 0;
}