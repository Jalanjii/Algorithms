#include <iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, i;
	cin >> n;
	for (i = 2; i < n; i++) {
		if ((n % i) == 0) {
			cout << i;
			break;
		}
	}
	return 0;
}