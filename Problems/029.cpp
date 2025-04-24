#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, n;
	cin >> n;
	if (n == 1) {
		cout << "No";
		return 0;
	}
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}