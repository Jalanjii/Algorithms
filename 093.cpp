#include <iostream>
//#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int big, sml;
	string s1, bigs, s2, smls;
	getline(cin, s1);
	getline(cin, s2);
	int l1 = s1.length(), l2 = s2.length();
	if (l1 >= l2) {
		big = l1; bigs = s1;
		sml = l2; smls = s2;
	}
	else {
		big = l2; bigs = s2;
		sml = l1; smls = s1;
	}
	for (int i = 0; i < sml; i++) {
		if (char(s1[i]) == char(s2[i]))
			continue;
		else if (char(s1[i]) > char(s2[i])) {
			cout << s2;
			return 0;
		}
		else {
			cout << s1;
			return 0;
		}
	}
	cout << smls;
	return 0;
}