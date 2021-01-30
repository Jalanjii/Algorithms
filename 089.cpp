#include <iostream>
#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, newstr = "", sub1, sub2;
	getline(cin, s);
	getline(cin, sub1);
	getline(cin, sub2);

	size_t l = s.length();
	int len1 = sub1.length();
	int len2 = sub2.length();
	int e = abs(len1 - len2); // e accounts for the difference between words length.

	int a[2], b[2], big, sml; //to preserve the the order of lengths for less complex code
	string bsub, ssub;
	if (len1 >= len2) {
		big = len1;
		sml = len2;
		bsub = sub1;
		ssub = sub2;
	}
	else {
		big = len2;
		sml = len1;
		bsub = sub2;
		ssub = sub1;
	}

	for (int i = 0; i <= (l - big); i++) {
		if (s.substr(i, big) == bsub) {
			a[0] = i;
			a[1] = big + i - 1;
			
		}
	}
	for (int i = 0; i <= (l - sml); i++) {
		if (s.substr(i, sml) == ssub) {
			b[0] = i;
			b[1] = sml + i - 1;
		}
	}

	int k = a[0], j = b[0];

	for (int i = 0; i < l+e; i++) {

		if (b[0] <= i && big-- > 0) {// e to manage the correct shifting. O(l).
			newstr += s[k++];
			if (big == 0) {
				i -= e; 
				l -= e; 
			}
		}

		else if (a[0] <= i && sml-- > 0) {
			newstr += s[j++];
			if (sml == 0)
			{
				i += e;
			}
		}

		else
			newstr += s[i];
	}

	cout << newstr;
	return 0;
}
--------------
#include <iostream>
#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, newstr = "", sub1, sub2;
	getline(cin, s);
	getline(cin, sub1);
	getline(cin, sub2);

	size_t l = s.length();
	int len1 = sub1.length();
	int len2 = sub2.length();
	int e = abs(len1 - len2); // e accounts for the difference between words length.

	int a[2], b[2], big, sml; //to preserve the the order of lengths for less complex code
	string bsub, ssub;
	if (len1 >= len2) {
		big = len1;
		sml = len2;
		bsub = sub1;
		ssub = sub2;
	}
	else {
		big = len2;
		sml = len1;
		bsub = sub2;
		ssub = sub1;
	}

	for (int i = 0; i <= (l - big); i++) {
		if (s.substr(i, big) == bsub) {
			a[0] = i;
			a[1] = big + i - 1;
			
		}
	}
	for (int i = 0; i <= (l - sml); i++) {
		if (s.substr(i, sml) == ssub) {
			b[0] = i;
			b[1] = sml + i - 1;
		}
	}

	int k = a[0], j = b[0];

	for (int i = 0; i < l+e; i++) {

		if (b[0] <= i && big-- > 0) {// e to manage the right shifting. O(l).
			newstr += s[k++];
			if (big == 0) {
				i -= e; 
				l -= e; 
			}
		}

		else if (a[0] <= i && sml-- > 0) {
			newstr += s[j++];
			if (sml == 0)
			{
				i += e;
			}
		}

		else
			newstr += s[i];
	}

	cout << newstr;
	return 0;
}
--------
#include <iostream>
#include <cmath>
//#include <climits>
#include <string>
//#include <algorithm>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, newstr = "", sub1, sub2;
	getline(cin, s);
	getline(cin, sub1);
	getline(cin, sub2);

	size_t l = s.length();
	int len1 = sub1.length();
	int len2 = sub2.length();
	int e = abs(len1 - len2); // e accounts for the difference between words length.

	int a[2], b[2], big, sml;
	string bsub, ssub;
	if (len1 >= len2) {
		big = len1;
		sml = len2;
		bsub = sub1;
		ssub = sub2;
	}
	else {
		big = len2;
		sml = len1;
		bsub = sub2;
		ssub = sub1;
	}

	for (int i = 0; i <= (l - big); i++) {
		if (s.substr(i, big) == bsub) {
			a[0] = i;
			a[1] = big + i - 1;
			
		}
	}
	for (int i = 0; i <= (l - sml); i++) {
		if (s.substr(i, sml) == ssub) {
			b[0] = i;
			b[1] = sml + i - 1;
		}
	}

	int k = a[0], j = b[0];

	for (int i = 0; i < l+e; i++) {

		if (b[0] <= i && big-- > 0) {
			newstr += s[k++];
			if (big == 0) {
				i -= e;
				l -= e;
			}
		}

		else if (a[0] <= i && sml-- > 0) {
			newstr += s[j++];
			if (sml == 0)
			{
				i += e;
			}
		}

		else
			newstr += s[i];
	}

	cout << newstr;
	return 0;
}
