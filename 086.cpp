#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	getline(cin, s);
	char l;
	cin >> l;
	for (int i = 0; i < s.length(); i++) {
		if (l == s[i]) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}