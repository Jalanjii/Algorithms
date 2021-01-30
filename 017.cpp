#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int cx, cy, r, ax, ay;
	cin >> cx >> cy >> r >> ax >> ay;
	if (pow((ax-cx),2) + pow((ay - cy),2) == pow(r,2)) {
		cout << 1;
	}
	else 
		cout << 0;

	return 0;
}