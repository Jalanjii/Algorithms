#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k;
	cin >> k;
	bool p = true;
	if (k >= 2) {
		cout << 2 << " ";
	}
	for (i = 3; i <= k; i+=2) {
		for (j = 3; j <= sqrt(i); j+=2) {
			if (i % j == 0) {
				p = false;
				break;
			}
		}
		if (p) {
			cout << i << " ";
		}
		p = true;
	}
	return 0;
}