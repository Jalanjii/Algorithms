#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <string>

using namespace std;

int ElementFind(int l, int r, int k, int n) {

	//determining the section for elm search
	int firstElement, l1, r1;
	cout << "? " << 1 << endl;
	cin >> firstElement;
	if (firstElement <= k) {
		l1 = 1, r1 = l;
	}
	else {
		l1 = r, r1 = n;
	}

	int currentElement, mid;
	//determining whether the element exist
	while (l1 <= r1) {

		mid = (l1 + r1) / 2;
		cout << "? " << mid << endl;
		cin >> currentElement;

		if (currentElement == k) {
			return mid;
		}
		if (currentElement < k) {
			l1 = mid + 1;
		}
		else {
			r1 = mid - 1;
		}
	}
	return -1;
}

int main() {
	cout.flush();
	int n, m, k, mid, currentElement, lElement;
	cin >> n >> m >> k;
	int l = 1, r = n+1, res;
	cout << "? " << l << endl;
	cin >> lElement;
	//determinning beg of sorted array
	while (r - l > 1) {
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
	//elm find check
	res = ElementFind(l, r, k, n);
	cout << "! " << res << endl;
	for (int i = 0; i < m - 1; i++) {
		cin >> k;
		res = ElementFind(l, r, k, n);
		cout << "! " << res << endl;

	}
	return 0;
}