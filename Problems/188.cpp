#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	size_t n, v;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cout << i + 1 << ':';
		for (size_t j = 0; j < n; j++) {
			cin >> v;
			if (v)
				cout << " " << j + 1;
		}
		cout << endl;
	}
	return 0;
}