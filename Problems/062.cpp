#include <iostream>
#include <cmath>
//#include <climits>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;

	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//selection sort, time complexity O(n^2)
	for (int i = 0; i < n-1; i++)
	{ int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_idx]) { min_idx = j; }	
		}
		swap(a[min_idx], a[i]);
	}

	for (int i = 0; i < n; i++) { cout << a[i] << " "; }
	return 0;
}