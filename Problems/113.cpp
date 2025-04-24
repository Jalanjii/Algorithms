#include<iostream>
#include <string>

using namespace std;

void Hanoi(unsigned m, unsigned start, unsigned middle, unsigned end) {
	if (m == 1) {
		cout << m << " " << start << " " << end << endl;
	}
	else {
		Hanoi(m - 1, start, end, middle);
		cout << m << " " << start << " " << end << endl;
		Hanoi(m - 1, middle, start, end);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	unsigned n;
	cin >> n;
	Hanoi(n, 1, 2, 3);
	return 0;
}
