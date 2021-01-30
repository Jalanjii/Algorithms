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

int levenshtein_distance(string &s1, string &s2, int n, int m, vector<vector<int>> &lookup) {

	if (n == 0)
		return m;
	if (m == 0)
		return n;

	if (lookup[n - 1][m - 1] != -1)
		return lookup[n - 1][m - 1];

	if (s1[n - 1] == s2[m - 1])
		return lookup[n - 1][m - 1] = levenshtein_distance(s1, s2, n - 1, m - 1, lookup);

	return lookup[n - 1][m - 1] = 1 + min({
		levenshtein_distance(s1, s2, n - 1, m - 1, lookup),//Replace
		levenshtein_distance(s1, s2, n - 1, m, lookup), // Remove
		levenshtein_distance(s1, s2, n, m - 1, lookup) // Insert
	});
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str1, str2, s1, s2;
	getline(cin, str1);
	getline(cin, str2);

	s1 = norm(str1);
	s2 = norm(str2);

	int n = s1.length(), m = s2.length();
	vector<vector<int>> lookup(n, vector<int>(m, -1));
	cout.precision(6);
	cout << levenshtein_distance(s1, s2, n, m, lookup);
	return 0;
}