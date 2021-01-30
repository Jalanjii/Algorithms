#include <iostream>
//#include <cmath>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k = 1; cin >> n;
	string *a = new string[n];
	string *b = new string[n];
	cin >> a[0];
	b[0] = a[0];
	cout << a[0] << " ";
	bool tag = false;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < k; j++) { // optimization for not having O(n^2), on average.
			if (a[i] == b[j]) {
				tag = true;
			}
		}
		if (tag) {
			tag = false;
			continue;
		}
		else {
			cout << a[i] << " ";
			b[k++] = a[i];
		}
	}
	return 0;
}
--------
#include <iostream>
//#include <cmath>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k = 1; cin >> n;
	string *a = new string[n];
	string *b = new string[n];
	cin >> a[0];
	b[0] = a[0];
	cout << a[0] << " ";
	bool tag = false;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < k; j++) {
			if (a[i] == b[j]) {
				tag = true;
			}
		}
		if (tag) {
			tag = false;
			continue;
		}
		else {
			cout << a[i] << " ";
			b[k++] = a[i];
		}
	}
	return 0;
}