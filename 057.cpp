#include <iostream>
//#include <cmath>
//#include <climits>
#define SIZE 100000

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int k, a[SIZE];
	int p;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> p;
	p = p - 1;
	for (int i = p; i < n; i++) {
		a[i] = a[i+1];
	}
	for (int i = 0; i < n-1; i++) {
		cout << a[i] << " ";
	}
	return 0;
}