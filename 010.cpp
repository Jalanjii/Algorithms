#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int num;
	cin >> num;
	int a, b, c;
	a = (num / 100) % 10;
	b = (num / 10) % 10;
	c = num % 10;
	cout << a << " " << b << " " << c;
	return 0;
}