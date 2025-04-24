#include <iostream>
//#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a, k; k = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a % 2 == 0) { k += a; }
	}
	cout << k;
	return 0;
}