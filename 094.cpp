#include <iostream>
//#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, sub;
	getline(cin, s);
	getline(cin, sub);

	long long int l = s.length(), i, k;
	long long int len = sub.length();

	for (i = 0; i <= l - len; i++) {

		for (k = 0; k < len; k++)
			if (s[i + k] != sub[k])
				break;

		if (k == len)
			cout << i+1;
	}
	return 0;
}