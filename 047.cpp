#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, p, v, c;
	cin >> n;
	v = 1000000000; c = 0;
	while (v) {
		p = (n / v) + c;
		if (p != 0) {
			c += 1;	
		}
		v /= 10;
	}
	cout << c;
	return 0;
}