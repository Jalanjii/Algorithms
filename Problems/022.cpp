#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a; cin >> a;
	if ((a % 111) == 0 || (a/10) % 11 ==0 || (a % 100) % 11 == 0 || (a / 100) == (a % 10)) {
		cout << 0;
	}
	else
		cout << 1;
	return 0;
}