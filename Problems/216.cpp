#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void substring(string &str, string &sub) {

	//Compute failure/prefix function
	vector<int> failure(sub.size(), -1);
	int char_matched_sub = -1;
	for (size_t i = 1; i < sub.size(); i++) {
	    
        while (char_matched_sub != -1 && sub[char_matched_sub + 1] != sub[i])
            char_matched_sub = failure[char_matched_sub];

		if (sub[char_matched_sub + 1] == sub[i])
			failure[i] = char_matched_sub++;
	}
    
	//KMP-Search pattern
	int char_matched = -1;
	for (size_t i = 0; i < str.size(); i++) {

		while (char_matched != -1 && str[i] != sub[char_matched + 1])
		    char_matched = failure[char_matched];
		
		if (str[i] == sub[char_matched + 1])
			char_matched++;
        
		if (char_matched == sub.size() - 1) {
			cout << i - char_matched + 1 << ' ';
			char_matched = failure[char_matched];
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m;
	string s, sub;
	getline(cin, s);
	cin >> m;
	
	while (m) {
		cin >> sub;
		substring(s, sub);
		m--;
		cout << endl;
	}

	return 0;
}