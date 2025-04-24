#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c, delta;
	double x1, x2, x;
	cin >> a >> b >> c;
	delta = ((b*b) - (4 * a * c));
	if (a == 0) {
		if (b == 0 && c == 0) {
			cout << "-1";
		}
		else if (b == 0 && c != 0) {
			cout << 0;
		}
		else {
			x = -(c*1.0) / b;
			cout << 1 << " " << x;
		}
	}
	else {
		if (delta > 0)
		{
			const double discrim = sqrt(delta);
			x1 = (-((b) - discrim)*1.0) / (2 * a);
			x2 = (-((b) + discrim)*1.0) / (2 * a);
			if (x1 < x2) {
				cout << 2 << " " << x1 << " " << x2;
			}
			else if (x1 == x2) {
				cout << 1 << " " << x1;
			}
			else {
				cout << 2 << " " << x2 << " " << x1;
			}
		}
		else if (delta == 0)
		{
			x = (-(b)*1.0) / (2 * a);
			cout << 1 << " " << x;
		}
		else {
			cout << 0;
		}
	}
	return 0;
}

----------------------------

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c, delta;
	double x1, x2, x;
	cin >> a >> b >> c;
	delta = ((b*b) - (4 * a * c));
	if (a == 0) {
		if (b == 0 && c == 0) {
			cout << "-1";
		}
		else if (b == 0 && c != 0) {
			cout << 0;
		}
		else {
			x = -(c*1.0) / b;
			cout << 1 << " " << x;
		}
	}
	else {
		if (delta > 0)
		{
			const double discrim = sqrt(delta);
			x1 = (-((b) - discrim)*1.0) / (2 * a);
			x2 = (-((b) + discrim)*1.0) / (2 * a);
			if (x1 < x2) {
				cout << 2 << " " << x1 << " " << x2;
			}
			else {
				cout << 2 << " " << x2 << " " << x1;
			}
		}
		else if (delta == 0)
		{
			x = (-(b)*1.0) / (2 * a);
			cout << 1 << " " << x;
		}
		else {
			cout << 0;
		}
	}
	return 0;
}