#include <iostream>
//#include <cmath>
//#include <climits>
#define SIZE 100000

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int k;
	int p; p = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k % 2 == 0) { cout << k << " "; }
	}

	return 0;
}