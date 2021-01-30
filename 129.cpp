#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
//#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

double min_time(double a, double b, int vel_p, int vel_f) {//min_time assumed being unimodal
	double dist1 = sqrt((b*b) + ((1 - a)*(1 - a)));
	double dist2 = sqrt((a*a) + ((1 - b)*(1 - b)));//pythog theorem to determine distance (hypotenuse)
	double t1 = dist1 / vel_p;//famous equation t = d / v
	double t2 = dist2 / vel_f;
	return t1 + t2;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int vel_p, vel_f;
	double l = 0, r = 1, a, mid1, mid2;
	cin >> vel_p >> vel_f >> a;

	//ternary search
	while (r - l > 0.00000001) {
		mid1 = l + (r - l) / 3;
		mid2 = r - (r - l) / 3;

		double f1 = min_time(a, mid1, vel_p, vel_f), f2 = min_time(a, mid2, vel_p, vel_f);

		if  (f1 > f2)
			l = mid1;

		else if (f1 < f2)
			r = mid2;
		else {
			l = mid1;
			r = mid2;
		}

	}

	cout.precision(8);
	cout << fixed << l;
	return 0;
}