#include <iostream>
//#include <cmath>
//#include <climits>
//#include <algorithm>
#define RANGE 100001
using namespace std;

void sorter(int n, int count[]) {
	for (int i = 0; i < n; i++) { int m; cin >> m; ++count[m]; }
	for (int m = 0; m < RANGE; ++m) {
		for (int k = count[m]; k; --k) {
			cout << m << ' ';
		}
	}
}

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, n; cin >> n;
	int count[RANGE]{};
	
	sorter(n, count);
	
	return 0;
}
