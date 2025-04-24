#include <iostream>
#include <cmath>

using namespace std;

int ntod(int n, int d) {
	int p = pow(n, d);
	return p;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, d;
	cin >> n >> d;
	cout << ntod(n, d);
	return 0;
}
