#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long i, a, b, m, k;
	cin >> a >> b;
	if (a > b) { m = a; k = b; }
	else { m = b; k = a; }
	i = m;
	for (i = m; i <= (a*b); i = i + m) {
		if (i % k == 0) { //we don't check for m because i+m is already a multiple
			cout << i;
			break;
		}
		
	}
	return 0;
}