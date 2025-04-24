#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;
	cin >> a >> b;
	if (((a % 2) == 0 && (b % 2) != 0) || (((b % 2) == 0 && (a % 2) != 0)))
	{
		cout << 1;
	}
		
	else
		cout << 0;
	return 0;
}