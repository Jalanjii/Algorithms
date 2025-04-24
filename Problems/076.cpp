#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

int Sub(int a[], int b[], int n, int m) {

	int *c = new int[n];

	int num1, num2, k = 0;

	for (int i = n - 1; i >= 0; i--) { 

		num1 = a[i];
		if (m - 1 - k >= 0 && m - 1 - k < m)
			num2 = b[m - 1 - k];
		else
			num2 = 0;
		
		if (num1 < num2) {
			num1 = num1 + 10;
			a[i - 1] = a[i - 1] - 1;
		}
		c[i] = num1 - num2;
		k++;
			
	}
	bool tag = false;

	for (int i = 0; i < n; i++) {

		if (i == 0 && c[i] == 0) {
			tag = true;
			continue;
		}

		else if (tag) {
			if (c[i] == 0 && i != n-1)
				continue;
		}

		cout << c[i];
		tag = false;	
	}	
	return 0;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int *a = new int[n];
	int *b = new int[m];
	bool tag = false;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++)
		cin >> b[i];


	if (n > m)
		Sub(a, b, n, m);

	else if (n == m) {
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i])
				tag = true;
		}
			
		if (tag) {
			cout << "-";
			Sub(b, a, m, n);
		}
		else
			Sub(a, b, n, m);
	}

	else {
		cout << "-";
		Sub(b, a, m, n);
	}
	
	return 0;
}