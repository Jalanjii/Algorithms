#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s; cin >> s;

	int res = 0, v = pow(10, s.length()-1);
	bool tag = false;
	for (int i = 0; i <= s.length(); i++) {
		char c = s[i];
		int k = s[i] - '0';
		if (c == '-') {
			k = (k / 3)*-1;
			k = 0;
			tag = true;
		}
		res += k*v;
		v /= 10;
	}
	if (tag)
		res *= -1;
	
	cout << res;

	return 0;
}