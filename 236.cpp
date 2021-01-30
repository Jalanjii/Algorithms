#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <regex>
//#include <algorithm>
//#include <sstream>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str;
	regex r(R"raw(((0[1-9]|[12]\d)(?=.(0[1-9]|1[0-2]))|3[01](?=.(01|0[3-9]|1[0-2]))|(0[1-9]|1[0-2])(?=.([12]\d))|(01|0[3-9]|1[0-2])(?=.3[01]))(\...\.|/../)\d\d(\d\d)?)raw");
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