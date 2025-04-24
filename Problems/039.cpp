#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k; cin >> n;
	for (k = 0; k <= log2(n); k++) {
		if (pow(2, k) == n) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}