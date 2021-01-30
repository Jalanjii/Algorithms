#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
//#include <cmath>
//#include <climits>
//#include <algorithm>

using namespace std;

char lower(char c) {
	if (c <= 'Z' && c >= 'A')
		return c - ('Z' - 'z');
	return c;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, str;
	while (getline(cin, s))
		str += s;

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (isalpha(c) || isdigit(c) || isspace(c))
			cout << lower(c);
	}

	return 0;
}