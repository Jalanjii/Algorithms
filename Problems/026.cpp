#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, i;
	cin >> n;
	for (i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0) {
			cout << n/i;
			break;
		}
	}
	return 0;
}