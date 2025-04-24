#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string norm(string &s) {
	string ans, words;
	for (int i = 0; i < s.size(); i++) {
		if ((isalpha(s[i])) || (isdigit(s[i])) || (s[i] == ' ')) {
			if (s[i] >= 'A' && s[i] <= 'Z')
				ans += tolower(s[i]);
			else
				ans += s[i];
		}
	}
	string ans2;
	int i = 0;
	while (i < ans.size()) {
		if (ans[i] != ' ') {
			ans2 += ans[i];
			i++;
		}
		else {
			ans2 += ans[i];
			while (ans[i] == ' ')
				i++;
		}

	}
	string ans3;
	i = 0;
	while (i < ans2.size()) {
		if (ans2[i] == ' ') {
			if (words.size() > 3)
				ans3 += words + ' ';
			words.clear();
		}
		else
			words += ans2[i];
		i++;
	}

	if (words.size() > 3)
		ans3 += words;
	return ans3;
}

double jaccard_index(string &s1, string &s2) {

	double sum = 0;
	int length_s1 = s1.length(), length_s2 = s2.length();
	for (int i = 0; i < min(length_s1, length_s2); i++)
		if (s1[i] == s2[i])
			sum++;

	double ratio = (sum) / (length_s1 + length_s2 - sum);
	return ratio;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str1, str2, s1, s2;
	getline(cin, str1);
	getline(cin, str2);

	s1 = norm(str1);
	s2 = norm(str2);

	cout.precision(6);
	cout << fixed << jaccard_index(s1, s2);

	return 0;
}
----------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string space_remove(string s) {
	string ans;
	int i = 0;
	while (i < s.size()) {
		if (s[i] != ' ') {
			ans += s[i];
			i++;
		}
		else {
			ans += s[i];
			while (s[i] == ' ')
				i++;
		}

	}
	return ans;
}

string k_limit(string s, int k) {
	string words, ans;
	int i = 0;
	while (i < s.size()) {
		if (s[i] == ' ') {
			if (words.size() > 3)
				ans += words + ' ';
			words.clear();
		}
		else
			words += s[i];
		i++;
	}

	if (words.size() > 3)
		ans += words;
	return ans;
}

string spe_char_remove(string s) {
	string ans;
	for (int i = 0; i < s.size(); i++) {
		if ((isalpha(s[i])) || (isdigit(s[i])) || (s[i] == ' ')) {
			if (s[i] >= 'A' && s[i] <= 'Z')
				ans += tolower(s[i]);
			else
				ans += s[i];
		}
	}
	ans = space_remove(ans);
	ans = k_limit(ans, 3);
	return ans;
}

double jaccard_index(string s1, string s2) {

	double sum = 0;
	int length_s1 = s1.length(), length_s2 = s2.length();
	for (int i = 0; i < min(length_s1, length_s2); i++)
		if (s1[i] == s2[i])
			sum++;

	double ratio = (sum) / (length_s1 + length_s2 - sum);
	return ratio;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str1, str2, s1, s2;
	getline(cin, str1);
	getline(cin, str2);

	s1 = spe_char_remove(str1);
	s2 = spe_char_remove(str2);

	cout.precision(6);
	cout << fixed << jaccard_index(s1, s2);

	return 0;
}