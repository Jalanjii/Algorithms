#include <iostream>
//#include <cmath>
//#include <climits>
#include <algorithm>
#define RANGE 100001
using namespace std;

int mini(int a, int b) {
	return min(a, b);
}

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b; cin >> a >> b;
	cout << mini(a, b);
	return 0;
}