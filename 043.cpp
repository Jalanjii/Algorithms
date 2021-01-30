#include <iostream>
//#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, q, r, c; c = 0;
	cin >> a >> b;
	if (a < b) { q = 0; r = a; cout << q << " " << r; return 0; }
	if (a == b) { q = 1; r = 0; cout << q << " " << r; return 0; }
	if (b == 1) { q = a; r = 0; cout << q << " " << r; return 0; }
	if (a > b) {
		while (a - b >= 0) {
			r = a - b;
			a = r;
			c++;
		}
	q = c; 
	cout << q << " " << r;
	}
	return 0;
}