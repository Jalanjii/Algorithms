#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <map> 
//#include <cmath>
//#include <climits>
//#include <algorithm>

using namespace std;

struct AC {

	struct Vertex {

		map<char, int> children;
		int        parent = -1;
		int   suffix_link = -1;
		int end_word_link = -1;
		int       word_length = 0; /**/
		char parent_char;
		bool leaf = false;
	};

	int root;
	void add_string(string s);
	void prepare();
	void process(string const& text, vector<string> const& vec);
	void CalcSuffLink(int vertex);
	vector<Vertex> trie;
	vector<string> vec;

public:

	AC()
		: root(0), trie(1) {
	}
};

void AC::add_string(string s) {

	int curVertex = root;

	for (char c : s) {

		if (trie[curVertex].children.find(c) == trie[curVertex].children.end()) {
			trie.emplace_back();
			trie.back().parent = curVertex;
			trie.back().parent_char = c;
			trie[curVertex].children[c] = trie.size() - 1;
		}

		curVertex = trie[curVertex].children[c];
	}

	trie[curVertex].leaf = true;
	trie[curVertex].word_length = s.size();
}

void AC::prepare() {

	queue<int> vertexQueue{};
	vertexQueue.push(root);

	while (!vertexQueue.empty()) {

		int curVertex = vertexQueue.front();
		vertexQueue.pop();

		CalcSuffLink(curVertex);

		for (auto& p : trie[curVertex].children)
			vertexQueue.push(trie[curVertex].children[p.first]);
	}
}

void AC::process(string const& text, vector<string>const& vec) {

	map<string, vector<size_t>> mp;
	int currentState = root;

	for (size_t j = 0; j < text.size(); j++) {

		while (true) {
			if (trie[currentState].children.find(text[j]) != trie[currentState].children.end()) {

				currentState = trie[currentState].children[text[j]];
				break;
			}

			if (currentState == root)
				break;

			currentState = trie[currentState].suffix_link;
		}

		int checkState = currentState;

		while (true) {

			checkState = trie[checkState].end_word_link;
			if (checkState == root)
				break;

			int indexOfMatch = j + 1 - trie[checkState].word_length;
			mp[string(text.data() + indexOfMatch, trie[checkState].word_length)].push_back(indexOfMatch);
			checkState = trie[checkState].suffix_link;
		}
	}

	for (auto& s : vec) {

		for (auto i : mp[s]) {

			cout << i + 1 << ' ';
		}
		cout << endl;
	}
}

void AC::CalcSuffLink(int vertex) {

	if (vertex == root) {

		trie[vertex].suffix_link = root;
		trie[vertex].end_word_link = root;
		return;
	}

	if (trie[vertex].parent == root) {

		trie[vertex].suffix_link = root;

		if (trie[vertex].leaf)
			trie[vertex].end_word_link = vertex;
		else
			trie[vertex].end_word_link = trie[trie[vertex].suffix_link].end_word_link;

		return;
	}

	int curBetterVertex = trie[trie[vertex].parent].suffix_link;
	char chVertex = trie[vertex].parent_char;

	while (true) {

		if (trie[curBetterVertex].children.find(chVertex) != trie[curBetterVertex].children.end()) {

			trie[vertex].suffix_link = trie[curBetterVertex].children[chVertex];
			break;
		}

		if (curBetterVertex == root) {

			trie[vertex].suffix_link = root;
			break;
		}

		curBetterVertex = trie[curBetterVertex].suffix_link;
	}

	if (trie[vertex].leaf)
		trie[vertex].end_word_link = vertex;
	else
		trie[vertex].end_word_link = trie[trie[vertex].suffix_link].end_word_link;
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k;
	string s, subs;
	cin >> s;
	cin >> k;

	AC aho;

	vector<string> vec;
	vec.reserve(k);
	for (int i = 0; i < k; i++) {

		cin >> subs;
		aho.add_string(subs);
		vec.push_back(move(subs));
	}

	aho.prepare();
	aho.process(s, vec);

	return 0;
}