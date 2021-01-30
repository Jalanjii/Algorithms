#include <iostream>
//#include <cmath>
//#include <climits>
#define RANGE 100000
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m; 

	int *L = new int[n];
	int *R = new int[m];
	int *a = new int[m+n];

	for (int i = 0; i < n; i++) { cin >> L[i]; }
	for (int i = 0; i < m; i++) { cin >> R[i]; }

	int i = 0, j = 0, k = 0;
	while (i < n && j < m)
	{   if (L[i] <= R[j]) { a[k] = L[i]; i++; }
		else { a[k] = R[j]; j++; }
		k++; 
	}
	while (i < n) { a[k] = L[i]; i++; k++; }
	while (j < m) { a[k] = R[j]; j++; k++; }

	for (int i = 0; i < m + n; i++) { cout << a[i] << " "; }
	return 0;
}