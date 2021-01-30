#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	long long int res;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	long long int *a = new long long int[n]; //using one array

	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (n == 1 || n == 2)
		res = a[0];

	else if (n == 3) {
		a[2] = a[2] + a[0];
		res = a[2];
	}

	else if (n == 4) {
		a[2] = a[2] + a[0];
		a[3] = a[3] + a[0];
		res = a[3];
	}

	else if (n == 5) {
		a[2] = a[2] + a[0];
		a[3] = a[3] + a[0];
		a[4] = a[4] + a[2];
		res = a[4];
	}
	else {
		a[2] = a[2] + a[0];
		a[3] = a[3] + a[0];
		a[4] = a[4] + a[2];
		for (int i = 5; i < n; i++) {
			long long int p1 = a[i] + a[i - 2], p2 = a[i] + a[i - 3];
			a[i] = max(p1, p2);
		}
		res = a[n - 1];
	}

	cout << res;
	return 0;
}
