#include <iostream>
//#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, sub, s1 = "";
	getline(cin, s);
	getline(cin, sub);

	long long int l = s.length(), i, k, beg, end;
	long long int len = sub.length();

	for (i = 0; i <= l - len; i++) {

		for (k = 0; k < len; k++)
			if (s[i + k] != sub[k])
				break;

		if (k == len) {
			beg = i;
			end = i + len - 1;
		}
	}
	for (int i = 0; i < l; i++) {
		if (i < beg || i > end) {
			s1 += s[i];
		}
		else {
			continue;
		}
	}
	cout << s1;
	return 0;
}