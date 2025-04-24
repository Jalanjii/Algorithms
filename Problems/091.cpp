#include <iostream>
//#include <cmath>
//#include <climits>
#include <string>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string s = "", s1;
	while (getline(cin, s1)) {
		s += s1; 
	}
	cout << s;
	return 0;
}