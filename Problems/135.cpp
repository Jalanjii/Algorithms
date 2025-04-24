#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>


using namespace std;

int query(int que) {
	int res;
	cout << "? " << que << endl;
	cin >> res;
	return res;
}

int bigmid(int l, int r) {

	while (l <= r) {

		int mid = (l + r) / 2;

		int middle = query(mid), previous = query(mid - 1), next = query(mid + 1);

		if (middle > previous && middle > next)
			return mid;

		else if (middle < previous)
			r = mid - 1;

		else
			l = mid + 1;
	}
}

int main() {

	cout.flush();

	int n;
	cin >> n;

	int l = 1, r = n;

	if (query(l) > query(l + 1))
		cout << "! " << l << endl;

	else if (query(r) > query(r - 1)) 
		cout << "! " << r << endl;

	else
		cout << "! " << bigmid(l, r) << endl;

	return 0;
}
-------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>


using namespace std;

int query(int que) {
	int res;
	cout << "? " << que << endl;
	cin >> res;
	return res;
}

int bigmid(int l, int r) {

	while (l <= r) {
		int mid = (l + r) / 2;

		int middle = query(mid), previous = query(mid - 1), next = query(mid + 1);

		if (middle > previous && middle > next)
			return mid;

		else if (middle < previous)
			r = mid - 1;

		else
			l = mid + 1;
	}
}

int main() {

	cout.flush();

	int l, r, n;

	cin >> n;

	l = 1, r = n;

	if (query(l) > query(l + 1)) {
		cout << "! " << l << endl;
		return 0;
	}

	if (query(r) > query(r - 1)) {
		cout << "! " << r << endl;
		return 0;
	}

	cout << "! " << bigmid(l, r) << endl;
	return 0;
}