#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, v, n1;
	cin >> n;
	v = int(log10(n))+1;
	k = pow(10, v-1);
	n1 = n;
	//if (v % 2 != 0) { cout << "No"; return 0; }
	v /= 2;
	while (v) {
		if (n / k != n1 % 10) {
			cout << "No";
			return 0;
		}
		n1 /= 10;
		n = (n % k);
		k /= 10;
		v--;
	}
	cout << "Yes";
	return 0;
}