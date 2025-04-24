#include <iostream>
//#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, i; i = 0;
	long long int a[100000];
	while (cin >> n)
	{
		a[i] = n;
		i++;
	}
	for (i = i-1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	return 0;
}