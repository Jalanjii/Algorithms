#include <iostream>
#include <string>


using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	getline(cin, s);

	for (int i = s.length()-1; i >= 0; i--) {
		cout << s[i];
	}

	return 0;
}