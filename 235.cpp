#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <regex>

#define VARIABLE "[a-zA-Z][a-zA-Z0-9]*(\\s*\\[\\s*([a-zA-Z][a-zA-Z0-9]*|\\d+)(\\s*[-+*\\/]\\s*([a-zA-Z][a-zA-Z0-9]*|\\d+))*\\s*\\])?"
#define ARGUMENT "(" VARIABLE "|\\d)(\\s*[-+*\\/]\\s*(" VARIABLE "|\\d))*"
#define FUNCTION "[a-zA-Z][a-zA-Z0-9]*\\s*\\(\\s*(" ARGUMENT "(\\s*,\\s*" ARGUMENT ")*)?\\s*\\)"
#define REGEX    VARIABLE "\\s*=\\s*(\\d+|" VARIABLE "|" FUNCTION ")(\\s*[-+*\\/]\\s*(\\d+|" VARIABLE "|" FUNCTION "))*\\s*;"

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string str;
	regex r(REGEX);
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