#include <iostream>
#include <algorithm>
//#include <cmath>
//#include <string>

using namespace std;

double f(double a, double b, double c, double d, double x) {
	return x*(x*(a*x + b) + c) + d;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double a, b, c, d, A = -30, B = 50, mid, eps = 0.000001, res;
	cin >> a >> b >> c >> d;

	// Bisection Search
	while (B-A > eps)
	{
		mid = (A + B) / 2;

		if (f(a, b, c, d, mid) == 0.0) {
			break;
		}

		if (f(a, b, c, d, mid) * f(a, b, c, d, A) < 0)
			B = mid;
		else
			A = mid;
	}

	res = mid;
	cout.precision(6);
	cout << fixed << res;

	return 0;
}
-------------
#include <iostream>
#include <algorithm>
//#include <cmath>
//#include <string>

using namespace std;

double f(double a, double b, double c, double d, double x) {
	return x*(x*(a*x + b) + c) + d;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double a, b, c, d, A = -30, B = 50, mid, eps = 0.000001, res;
	cin >> a >> b >> c >> d;

	// Bisection Search
	while (B-A > eps)
	{
		mid = (A + B) / 2;

		if (f(a, b, c, d, mid) == 0.0) {
			break;
		}

		if (f(a, b, c, d, mid) * f(a, b, c, d, A) < 0)
			B = mid;
		else
			A = mid;
	}

	res = mid;
	cout.precision(6);
	cout << fixed << res;

	return 0;
}
-------------
#include <iostream>
#include <algorithm>
//#include <cmath>
//#include <string>

using namespace std;

double f(double a, double b, double c, double d, double x) {
	return x*(x*(a*x + b) + c) + d;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double a, b, c, d, A = -30, B = 50, mid, eps = 0.000001, res;
	cin >> a >> b >> c >> d;

	// Bisection Search
	while (B-A > eps)
	{
		mid = (A + B) / 2;

		if (f(a, b, c, d, mid) == 0.0) {
			break;
		}

		if (f(a, b, c, d, mid) * f(a, b, c, d, A) < 0)
			B = mid;
		else
			A = mid;
	}

	res = mid;
	cout.precision(6);
	cout << fixed << res;

	return 0;
}