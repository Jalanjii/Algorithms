#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
//#include <cmath>
//#include <string>

using namespace std;

int occur(int a[], int n, int k) {
	int first, last, l = 0, r = n;
	bool found = false;
	//first occur
	while (l <= r) {
		int mid = (l + r) / 2;
		if (k == a[mid])
			found = true;
		if (k <= a[mid]) {
			r = mid - 1;
		}
			
		else
			l = mid + 1;
	}

	first = l;

	//last occur
	l = 0, r = n;
	while (l < r) {

		int mid = (l + r) / 2;

		if (k >= a[mid])
			l = mid + 1;
			
		else
			r = mid;
	}
	last = l - 1;
	if (found)
		cout << last - first + 1 << endl;
	else
		cout << "Not found" << endl;
	return 0;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k, m, n;
	cin >> n;
	int l = 0, r = n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> k;
		occur(a, n, k);
	}
	delete[] a;
	return 0;
}