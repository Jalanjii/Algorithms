#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <regex>
//#include <algorithm>
//#include <sstream>
//#include <cmath>
//#include <climits>


using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str, variable = "[a-zA-Z][a-zA-Z0-9]*(\\[([a-zA-Z][a-zA-Z0-9]*|\\d+)\\])?";
	regex r(variable + "\\s*=\\s*(" + variable + "|\\d+)(\\s*[-+*\\/]\\s*(" + variable + "|\\d+))*\\s*;");
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