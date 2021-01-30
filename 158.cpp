#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std; 

long long int numberofways(long long int a[], int n, long long int s) {

	long long int *res = new long long int[s + 1];

	for (int i = 0; i < s; i++)
		res[i] = 0;

	res[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = a[i]; j <= s; j++) {
			long long int ind = j - a[i];
			long long int inc = (res[j] + res[ind]) % 1000000007;
			res[j] = inc;
		}
				

	return res[s];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	long long int s;
	cin >> n >> s;

	long long int *a = new long long int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << numberofways(a, n, s);

	delete[] a;
	return 0;
}