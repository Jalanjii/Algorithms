#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

bool check(double x, int t[], int v[], int l, int n) {

	double d1 = 0, tm1 = 0;
	double d2 = 0, tm2 = x;
	int i = 0, j = 0;

	while (i < n && tm1 >= t[i]) {

		if (i != 0)
			d1 += (t[i] - t[i - 1]) * v[i];
		else
			d1 += (t[i]) * v[i];
		i++;
	}

	while (j < n && tm2 >= t[j]) {

		if (j != 0)
			d2 += (t[j] - t[j - 1]) * v[j];
		else
			d2 += (t[j]) * v[j];
		j++;
	}

	if (j != 0)
		d2 += (tm2 - t[j - 1]) * v[j];
	else
		d2 += tm2 * v[j];

	while (i < n && j < n) {
		if (d1 + l > d2)
			return false;
		if (t[i] - tm1 < t[j] - tm2) {
			double tmp = t[i] - tm1;
			d1 += tmp * v[i];
			i++;
			d2 += tmp * v[j];
			tm1 += tmp;
			tm2 += tmp;
		}
		else {
			double tmp = t[j] - tm2;
			d1 += tmp * v[i];
			d2 += tmp * v[j];
			j++;
			tm1 += tmp;
			tm2 += tmp;
		}
	}
	return d1 + l <= d2;
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int l, n;
	cin >> l >> n;

	int *t = new int[n];
	int *v = new int[n];

	for (int i = 0; i < n; i++)
		cin >> t[i] >> v[i];
	for (int i = 1; i < n; i++)
		t[i] += t[i - 1];

	double st = 0, dr = 1e9;
	for (int i = 0; i <= 150 && st < dr; i++) {
		double pivot = (st + dr) * 0.5;
		if (check(pivot, t, v, l, n))
			dr = pivot;
		else st = pivot;
	}

	cout.precision(3);
	cout << fixed << (st + dr) * 0.5;

	return 0;
}
-----------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

double Epsilon = 0.000001;

bool check(double x, int t[], int v[], int l, int n) {

	double d1 = 0, tm1 = 0;
	double d2 = 0, tm2 = x;// setting the time for the second train to be X
	int i = 0, j = 0;

	while (j < n && tm2 >= t[j]) {
		if (j != 0)
			d2 += (t[j] - t[j - 1]) * v[j];
		else
			d2 += (t[j]) * v[j];
		j++;
	}

	if (j != 0)
		d2 += (tm2 - t[j - 1]) * v[j];
	else
		d2 += tm2 * v[j];

	while (j < n) {
		if (d1 + l > d2)
			return false;
		// now we should advance the timers
		// we can do that using the smallest time available
		// and we do that in the if-else statement bellow
		double r1 = t[i] - tm1, r2 = t[j] - tm2;
		if (r1 - r2 < -Epsilon) {
			d1 += r1 * v[i];
			i++;
			d2 += r1 * v[j];
			tm1 += r1;
			tm2 += r1;
		}
		else {
			d1 += r2 * v[i];
			d2 += r2 * v[j];
			j++;
			tm1 += r2;
			tm2 += r2;

			// incrementing, if r1 closely equal to r2, for example: |difference| <= Epsilon
			// -e <= d we already checked, remains d <= e
			i += r2 <= Epsilon;
		}
	}

	return d1 + l <= d2;
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int l, n;
	cin >> l >> n;

	int *t = new int[n];
	int *v = new int[n];

	for (int i = 0; i < n; i++)
		cin >> t[i] >> v[i];
	for (int i = 1; i < n; i++)
		t[i] += t[i - 1];

	// smaller start interval
	// we don't have to wait longer than
	// first train needing for passing entire track
	double st = 0, dr = t[n - 1];;
	for (int i = 0; i <= 150 && st < dr; i++) {
		double pivot = (st + dr) * 0.5;
		if (check(pivot, t, v, l, n))
			dr = pivot;
		else
			st = pivot;
	}

	cout.precision(3);
	cout << fixed << (st + dr) * 0.5;

	return 0;
}
