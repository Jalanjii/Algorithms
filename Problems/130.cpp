#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <string>

using namespace std;

int main() {

	cout.flush();
	int n, l = 1, currentElement, mid;
	cin >> n;
        n++;
	int r = n;

	while (r - l >= 1) {

		mid = (r + l) / 2;
		cout << "? " << mid << endl;
		cin >> currentElement;

		if (currentElement < 1)
			l = mid + 1;
		else
			r = mid;

	}
	cout << "! " << n - r;

	return 0;
}