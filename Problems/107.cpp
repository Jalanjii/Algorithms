#include <iostream>
#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;

int stringcmp(string s1, string s2) {
	int len1 = s1.length(), len2 = s2.length();
	bool equal = true;
	if (len1 >= len2) {
		len1 = len1;
		len2 = len2;
	}
	else {
		swap(len1, len2);
	}

	for (int i = 0; i < len2; i++) {
		if (char(s1[i]) != char(s2[i]))
			equal = false;
	}
	if (equal && len1 == len2)
		return 1;
	else
		return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	cout << stringcmp(s1, s2);
	return 0;
}