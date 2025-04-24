#include <iostream>
#include <string>
//#include <cmath>


using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s; getline(cin, s);
	int l = s.length();
	char temp = s[0];
	for (int i = 0; i < l; i++) {
		char c = s[i];

		if (c == temp && i != 0) {
			c = temp;	
		}
		else {
			temp = c;
			cout << s[i];
		}
	}
	return 0;
}