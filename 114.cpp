#include <iostream>  // Implementing Known Memoiziation Version
#define SIZE 47
using namespace std;

int term[SIZE];

int fib_n(int n) {
	
	if (n == 1) {
		return 0;
	}
		
	if (n == 2) {
		return 1;
	}
		
	if (term[n] != 0)
		return term[n];
	else {
		term[n] = fib_n(n - 1) + fib_n(n - 2);
		return term[n];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	cout << fib_n(n);

	return 0;
}