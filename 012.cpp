#include <iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, rem;
	int i = 0;
	int b[5];//log_2(16)+1
	cin >> a;
	if (a == 0) {
		cout << 0;
	}
	while (a)
	{
		rem = a % 2;
		b[i++] = rem;
		a /= 2;
	}
	for (i = i - 1; i >= 0; i--)//i = i-1 because i 5.
	{
		cout << b[i];
	}
	return 0;
}