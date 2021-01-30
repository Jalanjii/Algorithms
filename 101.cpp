#include <iostream>
//#include <cmath>
//#include <climits>
#include <algorithm>
#define RANGE 100001
using namespace std;

int maxi(int a, int b) {
	return max(a, b);
}

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b; cin >> a >> b;
	cout << maxi(a, b);
	return 0;
}