#include <iostream>
//#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int n, a, b;
	int p, q, e; e = 0; q = 0; p = 0;
	cin >> n >> a;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> b;
		if (a > b) {
			p = 1;
			if (q) { cout << 0; return 0; }
		}
		if (a < b) {
			q = 1;
			if (p) { cout << 0; return 0; }
		}
		if (a == b) { e = 1; }
		a = b;
	}
	if (e) { cout << 1; }
	else { cout << 2; }
	return 0;
}