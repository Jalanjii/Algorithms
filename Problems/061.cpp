#include <iostream>
//#include <cmath>
#define SIZE 19

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int n, k; cin >> n >> k;
	if (n == 0) { cout << k; return 0; }
	else if (k == 0) { cout << n; return 0; }
	long long int npr = n, kpr = k;
	int an[SIZE], ak[SIZE], n_i = 0, k_i = 0;
	while (n) { an[n_i] = n % 10; n /= 10; n_i++; }
	while (k) { ak[k_i] = k % 10; k /= 10; k_i++; }

	if (n_i > k_i) { cout << npr; return 0; }
	if (n_i < k_i) { cout << kpr; return 0; }
	else {
		for (int i = n_i; i >= 0; i--) {
			if (an[i] > ak[i]) { cout << npr; return 0; }
			else if (an[i] < ak[i]) { cout << kpr; return 0; }
			else { continue; }
		}
	}
	cout << npr;
	return 0;
}