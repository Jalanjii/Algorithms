#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, n, count; cin >> n;
	count = 0;
	for (i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if ((n / i) != i) {
				count += 2;
			}
			else
				count++;
		}
			
	}
	cout << count;
	return 0;
}