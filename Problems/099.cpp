#include <iostream>
//#include <cmath>
//#include <climits>
//#include <algorithm>
#define RANGE 100001
using namespace std;

void uprounder(double a) {
	if ((a / 1) - int(a) == 0)
		cout << int(a);
	else
		cout << int(a) + 1;
}

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double a; cin >> a;
	
	uprounder(a);
	
	return 0;
}