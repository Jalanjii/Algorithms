#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int a;
	cin >> a;
	
	if ((a / 100) / 10 == (a % 100) % 10 && (a / 100) % 10 == (a % 100) / 10) {
		cout << 1;
	}
	else
		cout << 0;

	return 0;
}