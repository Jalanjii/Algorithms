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
	regex b("(([01]?\\d|2[0-3]):[0-5]\\d)($|[^\\d]|\\d?\\d:\\d?\\d)");
	smatch m;
	while (getline(cin, str)) {
		auto pos = str.cbegin();
		while (regex_search(pos, str.cend(), m, b)) {
			cout << m[1] << endl;;
			pos = m[1].second;
		}
	}
	return 0;
}