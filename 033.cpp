#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int a, b, l, t, i;
	cin >> a >> b;
	if (a > b) { l = a; t = b; }
	else { l = b; t = a; }
	if (l % t == 0) {
		cout << t;
		return 0; 
	}
	for (i = (t+1)/2; i >= 1 ; i--) {
		if (l % i == 0 && t % i == 0) {
			cout << i;
			break;
		}
	}
	return 0;
}