#include <iostream>		//O(nlog(n)) Time Complexity LIS Algorithm Discovered By Donald Knuth//

#include <cmath>
//#include <climits>
//#include <string>
#include<algorithm> 


using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int n; cin >> n;
	int length = 1;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	long long int *a = new long long int[n];
	long long int *len = new long long int[n];
	for (long long int i = 0; i < n; i++)
		cin >> a[i];

	len[0] = a[0];
	for (long long int i = 1; i < n; i++) // O(n)
	{
		if (a[i] < len[0]) {
			len[0] = a[i];
		}
		else if (a[i] > len[length - 1]) {
			len[length++] = a[i];
		}
		else {
			long long int beg = -1, end = length - 1, key = a[i];
			while (end - beg > 1) { // O(log(n)): Binary Search
				long long int mid = beg + (end - beg) / 2;
				if (len[mid] >= key) {
					end = mid;
				}
				else {
					beg = mid;
				}
			}
			len[end] = a[i];
		}
	}

	if (length == 1)
		length = -1;

	cout << length;

	return 0;
}
