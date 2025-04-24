#include <iostream>
//#include <cmath>
//#include <limits>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, n, res;
	cin >> n;
	res = 1;
	for (i = n; i > 1; i--) {
		res *= i;
	}
	cout << res;
	return 0;
}