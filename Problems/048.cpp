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
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a >= max && a % 2 == 0)
			max = a; 
		if (a <= min && a % 2 != 0)
			min = a;
	}

	if (min == BETTER_INF && min != 1)
		min = -1;
	
	cout << min << " " << max;
	return 0;
}