#include <iostream>
#include <cmath>

using namespace std;

int euc(int n, int n1) {

	int l, j, rem;
	if (n > n1) { l = n; j = n1; }
	else { l = n1; j = n; }
	if (j == 0) { return l; }
	if (l%j == 0) { return j; }
	rem = l % j;
	l = j;
	j = rem;
	return euc(l, j);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, n1;
	cin >> n >> n1;
	cout << euc(n, n1);
	return 0;
}