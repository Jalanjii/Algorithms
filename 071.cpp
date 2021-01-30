#include <iostream>
//#include <cmath>
//#include <climits>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, j = 0; cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			swap(a[i], a[j]);
			j++;
		}
		else
			j = j;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " " ;

	return 0;
}