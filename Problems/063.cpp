#include <iostream>
#include <cmath>
//#include <climits>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;
	bool swp = false;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) { swap(a[j], a[j + 1]); swp = true; }
		}
		if (!swp) { break; }
	}

	for (int i = 0; i < n; i++) { cout << a[i] << " "; }
	return 0;
}