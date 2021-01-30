#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s; cin >> s;
	int l = s.length();
	double res = 0;
	int D, v = pow(10, l - 1);
	bool neg = false, fra = false;
	for (int i = 0; i <= l; i++) {
		char c = s[i];
		int k = s[i] - '0';
		if (c == '-') {
			k = (k / 3)*-1;
			k = 0;
			neg = true;
		}
		if (c == '.') {
			D = v*10;
			l -= 1;
			fra = true;
			continue;
		}
		res += k*v;
		v /= 10;
	}
	if (neg)
		res = (res * (-1));
	if (fra)
		res = res / D;
	cout << res;

	return 0;
}