#include <iostream>
#include <cmath>
//#include <climits>
//#include <algorithm>

using namespace std;

int linelength(int a, int b) {
	 return abs(a - b);
}

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b; cin >> a >> b;
	cout << linelength(a, b);
	return 0;
}