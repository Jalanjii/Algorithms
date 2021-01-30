#include <iostream>
#include <cmath>
//#include <climits>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, n, k, num; i = 0;  cin >> n; k = int(log10(n)) + 1;
	if (n == 0) { cout << 0; return 0; }
	int *a = new int[k]; bool in[10]{};
	//inserting unique elements
	while (n) { num = n % 10;
		if (!in[num]) { a[i] = num; i++; in[num] = true; }
		n = n / 10; k = i;
	}
	//selection sort
	for (i = 0; i < k - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < k; j++) {
			if (a[j] < a[min_idx])
				min_idx = j;
		}
		swap(a[min_idx], a[i]);
	}

	for (int i = 0; i < k; i++) { cout << a[i] << " "; }
	return 0;
}