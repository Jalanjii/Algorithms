#include <iostream>
//#include <cmath>
#define SIZE 18

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int n, s, k; cin >> n >> s; int i = 0;
	long long int *a = new long long int[n];
	while (cin >> k) { a[i] = k; i++; }
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == s) { cout << i+1 << " " << j+1; return 0; }
		}
	}
	cout << -1;
	return 0; 
}