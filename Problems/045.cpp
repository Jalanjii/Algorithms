#include <iostream>
//#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a, b, c;
	cin >> n >> a >> b;
	if (a > b) { cout << 0; return 0; }
	c = b - a;
	for (int i = 2; i < n; i++)
	{
		a = b;
		cin >> b;
		if ((b-a) != c) { cout << 0; return 0; }
		if (a > b) { cout << 0; return 0; }
	}
	cout << 1;
	return 0;
}
