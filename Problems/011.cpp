#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	if (a != 0) 
		cout << (-b) / a;
	
	else if ((a == 0) && (b == 0))
		cout << "R";
	
	else 
		cout << "NO SOLUTION";
	
	return 0;
}