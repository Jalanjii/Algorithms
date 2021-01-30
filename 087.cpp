#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s; cin >> s;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		char c = s[i];
		if (c >= 65 && c <= 90) {
			c += 32;
			cout << char(c);
		}
		else {
			c -= 32;
			cout << char(c);
		}
	}
	return 0;
}