#include <iostream>
//#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int x1, x2;
	int l;
	cin >> x1 >> x2 >> l;
	cout << x1 << " ";
	while (x1 + l <= x2) {
		cout << x1 + l << " ";
		x1 = x1 + l;
	}
	return 0;
}