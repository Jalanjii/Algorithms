#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string norm(string &s) {
	string ans, ans2, ans3, words;
	for (int i = 0; i < s.size(); i++) {
		if ((isalpha(s[i])) || (isdigit(s[i])) || (s[i] == ' ')) {
			if (s[i] >= 'A' && s[i] <= 'Z')
				ans += tolower(s[i]);
			else
				ans += s[i];
		}
	}
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

bool plagiarism_check(string &s1, string &s2) {

	int n1 = s1.length(), n2 = s2.length();
	vector<string> s1_Words(n1), s2_Words(n2);
	int i = 0, index = 0;

	while (i < n1) {
		while (i < n1 && s1[i] != ' ') {
			s1_Words[index] += s1[i];
			i++;
		}
		index++;
		s1_Words[index].clear();
		i++;
	}

	int s1_NumberofWords = index;
	i = 0, index = 0;

	while (i < n2) {
		while (i < n2 && s2[i] != ' ') {
			s2_Words[index] += s2[i];
			i++;
		}
		index++;
		s2_Words[index].clear();
		i++;
	}

	int s2_NumberofWords = index;
	double sum = 0;
	for (int i = 0; i < s1_NumberofWords; i++) {
		for (int j = 0; j < s2_NumberofWords; j++) {
			if (jaccard_index(s1_Words[i], s2_Words[j]) > 0.45) {
				sum++;
			}
		}
	}

	double ratio = sum / (s1_NumberofWords + s2_NumberofWords - sum);
	if (ratio > 0.25)
		return true;
	else
		return false;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	vector<string> strings;

	while (getline(cin, s)) {
		s = norm(s);
		strings.push_back(s);
	}

	int n = strings.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (plagiarism_check(strings[i], strings[j]))
				cout << i + 1 << " " << j + 1 << endl;
		}
	}
	return 0;
}