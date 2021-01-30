#include <iostream>
#include <algorithm>
//#include <cmath>
//#include <string>

using namespace std;

int main() {

	cout.flush();
	int n, l = 1, currentElement;
	cin >> n;
        n++;
	int r = n;

	while (r - l >= 1)
	{
		int mid = (l + r) / 2;
		cout << "? " << mid << endl;
		cin >> currentElement;

		if (currentElement <= mid - 1)
			l = mid + 1;
		else
			r = mid;
	}

	cout << "! " << r-1;
	return 0;
}