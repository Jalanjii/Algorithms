#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, sum = 0, presum = 0;;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 1; i < n; i++) {
		presum += a[i-1];
		sum = sum - a[i];
		if (presum == sum-presum) {
			cout << i + 1;
			break;
		}
		sum = sum + a[i];
		
			
		
	}

	delete[] a;
	return 0;
}