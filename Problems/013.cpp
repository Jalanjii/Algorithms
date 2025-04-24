#include <iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int v1, v2;
	cin >> v1 >> v2;
	v1 = v1 + v2;
	v2 = v1 - v2;
	v1 = v1 - v2;
	cout << v1 << " " << v2;
}