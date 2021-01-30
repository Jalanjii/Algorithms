#include <iostream>
//#include <cmath>
#include <climits>
#define BETTER_INF  ((unsigned) ~0)
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	long long int a, min, max;
	cin >> n;
	min = BETTER_INF; max = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a >= max && a % 2 == 0) { max = a; }
		if (a <= min && a % 2 != 0) { min = a; }
	}

	if (min == BETTER_INF && min != 1) { min = -1; }
	if (max == -1) { max = -1; }
	cout << min << " " << max;
	return 0;
}

--------------

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, n1, l, j, rem;
	cin >> n >> n1;
	if (n > n1) { l = n; j = n1; }
	else { l = n1; j = n; }
	if (j == 0) { cout << l; return 0; }
	if (l%j == 0) { cout << j; return 0; }
	rem = l % j;
	while (l % j) {
		rem = l % j;
		l = j;
		j = rem;
	}
	cout << rem;
	return 0;
}