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
	regex r("[a-zA-Z0-9_]+@[a-zA-Z0-9.-]{1,61}\\.+[a-zA-Z]{2,4}");
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