#include <iostream>
#include <algorithm>
//#include <cmath>
#include <string>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, maxlength = 1;

	cin >> n;

	string *a = new string[n];
	for (int i = 0; i < n; i++) { // inputs/determinning maximum length
		int lens;
		cin >> a[i];
		lens = a[i].length();
		if (lens > maxlength)
			maxlength = lens;//maxlength determined
	}

	for (int i = 0; i < n; i++) { 
		string orglen, temp;
		orglen = to_string(a[i].length());
		temp = a[i];
		for (int j = 0; j <= maxlength; j++)
			a[i] += temp;
		a[i] = a[i].substr(0, maxlength + 1) + orglen;
	}

	sort(a, a + n);//simple sorting

	for (int i = n - 1; i >= 0; i--) {// we start from the end to get the biggest number.
		int c;
		string res;
		c = stoi(a[i].substr(maxlength + 1, int(log10(maxlength)) + 1));

		res = a[i].substr(0, c);
		cout << res;//we output
	}

	delete[] a;
	return 0;
}