//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <algorithm>
//#include <cmath>
#include <string>

using namespace std;


int binarySearch(string a[], string elm, int n)
{
	int l = 0;
	int r = n - 1;
	while (l <= r) {

		int mid = (l + r) / 2;

		if (a[mid] == elm) {
			return mid+1;
		}
		if (a[mid] <= elm) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return -1;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n;

	string *arr = new string[n], s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> k;
	while (k) {
		cin >> s;
		//cout << s << " ";
		cout << binarySearch(arr, s, n) << endl;
		k--;
	}
	delete[] arr;
	return 0;
}