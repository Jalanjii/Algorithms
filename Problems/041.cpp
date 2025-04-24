#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, n, fn, f1, f2; f1 = 0; f2 = 1; fn = 0; 
	cin >> n;
	if (n == 1) { cout << f1; return 0; }
	if (n == 2) { cout << f2; return 0; }
	for (i = 3; i <= n; i++) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	cout << fn;
	return 0;
}