#include <iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n1, n2;
	cin >> n1 >> n2;
	if ((n1 % 2) != 0)
		cout << n1;
	else
		cout << n2;
}