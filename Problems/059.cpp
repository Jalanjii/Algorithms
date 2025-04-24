#include <iostream>
//#include <cmath>
//#include <climits>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, m, count = 0; cin >> n >> k >> m;
	long long int *a = new long long int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = k-1; i < m; i++) {
		count += a[i];
	}
	cout << count;
	return 0;
}