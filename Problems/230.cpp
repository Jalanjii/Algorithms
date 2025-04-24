#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iterator>
#include <regex>
//#include <algorithm>
//#include <sstream>
//#include <cmath>
//#include <climits>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int index = 0;
	string str;
	regex r("^Merlin speaks.*(Avada-ke-davra)");
	smatch m;
	while (getline(cin, str)) {
		index++;
		if (regex_search(str, m, r))
			cout << index << " " << distance(str.cbegin(), m[1].first) + 1 << endl;
	}

	return 0;
}
