#include <iostream>
#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;

string ntos(int n) {
	string s = "";
	if (n < 0) {
		s = "-";
		n = -n;
	}
	char c;
	if (n == 0) {
		c = '0' + n;
		s += c;
		cout << s;
	}
	else {
		int len = int(log10(n)) + 1;
		int d = pow(10, len - 1), num = n;
		while (d) {
			n = num / d;
			c = n + '0';
			s += c;
			num = num % d;
			d /= 10;
		}
		return s;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int n;
	cin >> n;
	cout << ntos(n);
	return 0;
}