#include <iostream>
//#include <cmath>
//#include <climits>
//#include <algorithm>

using namespace std;

void swapper(int a, int b) {
	swap(a, b);
	cout << a << " " << b;
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	swapper(a, b);
	
	return 0;
}
