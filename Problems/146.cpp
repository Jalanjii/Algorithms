#include <iostream> //146//
#include <algorithm>
//#include <cmath>
//#include <string>

using namespace std;

int main() {
	cout.flush();
	int n, l = 1, mid, currentElement, lElement;
	cin >> n;
	int r = n;
	cout << "? " << l << endl;
	cin >> lElement;

	while (r - l >= 1) {

		mid = (r + l) / 2;

		cout << "? " << mid << endl;
		cin >> currentElement;
		
		if (lElement < currentElement) {
			l = mid;
			lElement = currentElement;
		}
		else {
			r = mid;
		}
	}

	cout << "! " << r%n;
	return 0;
}