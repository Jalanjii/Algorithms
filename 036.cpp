#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a, k, p, v, c;
	cin >> n;
	v = 1000000000;
	k = n; c = 0;
	while (v) {
		p = (n / v) + c;
		if (p != 0) {
			c = 1;
			a = (n / v);
			cout << a << " ";
			n = (n % v);
		}
		v /= 10;
	}
	cout << endl;
	while (k) {
		cout << k % 10 << " ";
		k /= 10;
	}
	return 0;
}

----------------

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, n, k, n1; cin >> n;
	n1 = n;
	//cout << int(log10(n)) + 1;
	for (k = pow(10, int(log10(n))); k > 0; k /= 10) {
		a = (n / k);
		cout << a << " ";
		n = (n % k);
	}
	cout << endl;
	while (n1) {
		cout << n1 % 10 << " ";
		n1 /= 10;
	}
	return 0;
}