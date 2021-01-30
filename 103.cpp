#include <iostream>
#include <cmath>
//#include <climits>
//#include <algorithm>
#define RANGE 100001
using namespace std;

int abv(int a) {
	return abs(a);
}

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a; cin >> a;
	cout << abv(a);

	return 0;
}