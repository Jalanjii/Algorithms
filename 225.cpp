#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <sstream>
#include <string>
//#include <algorithm>
#include <regex>
//#include <cmath>
//#include <climits>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str;
	regex r("((2[0-3]|[01]?\\d):[0-5]\\d)( (am|pm))?");
	regex r24("2[0-3]|[01]\\d");
	regex r24_12("2[0-3]|1[3-9]|0[0-9]");
	smatch m;
	while (getline(cin, str)) {
		auto pos = str.cbegin();
		while (regex_search(pos, str.cend(), m, r)) {
			if (m[3].first == m[3].second) {
				// 24h format only
				if (regex_match(m[2].first, m[2].second, r24)) {
					cout << m[0] << endl;
				}
			}
			else {
				if (regex_match(m[2].first, m[2].second, r24_12)) {
					auto sm = m[1];
					cout << sm << ' ';
					sm.first++;
					cout << sm << m[3] << endl;
				}
				else {
					cout << m[0] << endl;
				}
			}
			pos = m.suffix().first;
		}
	}
	return 0;
}