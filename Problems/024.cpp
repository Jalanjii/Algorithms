#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int h, m, ang;
	cin >> h >> m;
	ang = abs(m - (5 * h)) * 6;
	if (ang > 180)
	{
		cout << 360 - ang;
	}
	else
		cout << ang;
	return 0;
}