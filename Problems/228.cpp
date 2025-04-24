#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <regex>
//#include <cmath>
//#include <climits>
#include <algorithm>

using namespace std;

vector<pair<string::const_iterator, string::const_iterator>> longestMatchingBracketSequence(string const&str) {

	vector<string::const_iterator> stack;
	vector<pair<string::const_iterator, string::const_iterator>> results;
	smatch m;
	regex r("([({])|(\\))|\\}");

	auto pos = str.cbegin();
	size_t numberOfFixed = 0;

	while (regex_search(pos, str.cend(), m, r)) {

		pos = m.suffix().first;

		if (m[1].matched) {
			stack.push_back(m[1].first);
		}

		else if (!stack.empty() && *stack.back() == (m[2].matched ? '(' : '{')) {
			auto opening = stack.back();
			stack.pop_back();
			size_t index = results.size();

			if (index-- == numberOfFixed || !stack.empty() && results[index].first < stack.back()) {
				results.emplace_back(opening, pos);
			}
			else if (index-- == numberOfFixed || !stack.empty() && results[index].first < stack.back()) {
				results.back().first = min(results.back().first, opening);
				results.back().second = pos;
			}
			else {
				results[index].second = pos;
				results.pop_back();
			}
		}

		else {
			stack.clear();
			numberOfFixed = results.size();
		}
	}
	return results;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (string str; getline(cin, str);) {
		for (auto& i : longestMatchingBracketSequence(str)) {
			cout.write(&*i.first, distance(i.first, i.second));
			cout << endl;
			/*cout.write(&*i.first, distance(i.first, i.second));
			cout << " (" << distance(str.cbegin(), i.first) << ", " << distance(str.cbegin(), i.second) << ')';
			cout << endl;*/
		}
	}
	return 0;
}