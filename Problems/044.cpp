#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, k, fn, f1, f2; f1 = 0; f2 = 1; fn = 0;
	cin >> k;
	i = 3;
	if (k == f1) { cout << 1; return 0; }
	if (k == f2) { cout << 2; return 0; }
	while (true) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
		if (fn == k) { cout << i; break; }
		i++;
	}
	return 0;
}