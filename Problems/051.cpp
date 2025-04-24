#include <iostream>
//#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	long long int a[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	return 0;
}