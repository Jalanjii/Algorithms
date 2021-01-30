#include <iostream>
//#include <cmath>
#include <climits>
#define SIZE 100000

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int a[SIZE], min, max;
	int n, min_i, max_i; min = LLONG_MAX; max = -LLONG_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < min) { min = a[i]; min_i = i; }
		if (a[i] >= max) { max = a[i]; max_i = i; }
	}
	a[max_i] = min; a[min_i] = max;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}