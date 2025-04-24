#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
//#include <cmath>
//#include <climits>
#include <algorithm>

using namespace std;

int main() {
    
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, str, temp_s, ans;
	while (getline(cin, str)) {
	    str.erase(remove(str.begin(), str.end(), '\r'), str.end());
	    s += str;
    }
    
    string *arr = new string[s.length()];
    int k = 0;
	for (char c : s) {

		if (isalpha(c) || isdigit(c)) {
			c = tolower(c);
			temp_s += c;
		}

		if (isspace(c)) {
			if (temp_s.length() > 3) {
			    
				arr[k++] = temp_s;
				//ans += " ";
			}
			temp_s = "";
		}
	}
	
	if (temp_s.length() > 3)
	    arr[k++] = temp_s;
	    
	for (int i = 0; i < k; i++) {
	    if (i != k - 1) {
	        ans += arr[i];
	        ans += " ";
	    }
	    else
	        ans += arr[i];
	}
	    
	cout << ans;

	return 0;
}