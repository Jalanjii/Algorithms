#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, n, k, l;
	long long res, num, den;
	res = num = den = 1;
	cin >> n >> k;
	if (n < k) {
		cout << 0;
		return 0;
	}
	if (n == k || k == 0) {
		cout << 1;
		return 0;
	}
	if (k > (n / 2)) { //for more efficiency
		l = (n - k);
	}
	else {
		l = k;
	}
	for (i = 1; i <= l; i++) { 
		if ((n - i + 1) % i == 0) { // simplification of binomial coefficient formula.
			res = res * ((n - i + 1) / i); // optimizing by division so we don't have large multiplication
		}
		else {
			num *= (n - i + 1);
			den *= i;
		}	
	}
	cout << (res*num)/den;
	return 0;
}

---------------------

#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, n, k, v;
	long long res, num, den;
	res = num = den = 1;
	cin >> n >> k;
	if (n < k) {
		cout << 0;
		return 0;
	}
	if (n == k || k == 0) {
		cout << 1;
		return 0;
	}
	if (k > (n / 2)) {
		v = (n - k);
	}
	else {
		v = k;
	}
	for (i = 1; i <= v; i++) {
		if ((n - i + 1) % i == 0) {
			res = res * ((n - i + 1) / i);
		}
		else {
			num *= (n - i + 1);
			den *= i;
		}	
	}
	cout << (res*num)/den;
	return 0;
}