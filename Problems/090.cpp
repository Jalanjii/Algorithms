#include <iostream>
#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, s1 = "", s2 = "";
	getline(cin, s);
	int len = s.length();
	int n, c = 0; cin >> n;
	for (int i = 0; i < len; i++) {
		if (i < n && !c) {
			s1 += s[i];
			
		}
		else if (i == n) {
			c = 1;
			s2 += s[i];
		}
		else
			s2+= s[i];
	}
	cout << s1 << endl << s2;
	return 0;
}

------------

//#include <iostream>  // Implemented Known Memoiziation Version
//#define SIZE 47
//#define BOUND 2971215073;
//using namespace std;
//
//int term[SIZE];
//// 47th element
//
//int fib_i(int n) {
//
//	if (n == 1) {
//		return 0;
//	}
//
//	if (n == 2) {
//		return 1;
//	}
//
//	if (term[n] != 0)
//		return term[n];
//	else {
//		term[n] = fib_i(n - 1, i++) + fib_i(n - 2, i++);
//		return term[n];
//	}
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//
//	int i, n;
//	cin >> n;
//	cout << fib_i(n, i);
//
//	return 0;
//}

#include <iostream>
#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, s1 = "", s2 = "";
	getline(cin, s);
	int len = s.length();
	int n, c = 0; cin >> n;
	for (int i = 0; i < len; i++) {
		if (i < n && !c) {
			s1 += s[i];
			
		}
		else if (i == n) {
			c = 1;
			s2 += s[i];
		}
		else
			s2+= s[i];
	}
	cout << s1 << endl << s2;
	return 0;
}