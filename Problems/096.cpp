#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

void sums(int a, int b) {
	int res = a + b;
	cout << res;
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b; cin >> a >> b;
	sums(a, b);
	return 0;

}