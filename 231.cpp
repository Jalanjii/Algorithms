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
	regex r("[1-9]\\d*([-+*/][1-9]\\d*)*");
	smatch m;
	while (getline(cin, str)) {
		auto pos = str.cbegin();
		while (regex_search(pos, str.cend(), m, r)) {
			cout << m[0] << endl;
			pos = m.suffix().first;
		}
	}
	return 0;
}