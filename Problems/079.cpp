#include <iostream>
//#include <string>
//#include <cmath>
//#include <climits>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k, m; cin >> n;
	long long int *a = new long long int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;

	while (m--) {
		bool found = false;
		cin >> k;
		int l = 0, r = n-1;
		while (l <= r) {
			int p = l + (r - l) / 2;
			if (a[p] == k) {
				cout << p + 1 << endl;
				found = true;
				break;
			}
			else if (a[p] < k)
				l = p + 1;
			else
				r = p - 1;
		}
		if (!found)
			cout << "-1" << endl;
	}
	return 0;
}