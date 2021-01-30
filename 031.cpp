#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, n, count;
	count = 1;
	cin >> n;
	int k = numeric_limits<int>::max();
	bool p = true;
	if (n == 1) {
		cout << 2 << " ";
		return 0;
	}
	else
		cout << 2 << " ";
	for (i = 3; i <= k; i+=2) {
		for (j = 3; j <= sqrt(i); j+=2) {
			if (i % j == 0) {
				p = false;
				break;
			}
		}
		if (p) {
			cout << i << " ";
			count++;
			if (n == count) {
				break;
			}
		}
		p = true;
	}
	return 0;
}