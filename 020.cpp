#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int a; cin >> a;
	if (((a / 1000) % 100) / 10 + (a / 1000) / 100 + (a / 1000)
		% 10 == ((a % 1000) % 100) / 10 + (a % 1000) / 100 + (a % 1000) % 10) {

		cout << 1;
	}
	else
		cout << 0;
	return 0;
}