#include <iostream>
//#include <cmath>
//#include <climits>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, temp = 1, res = temp; 
	cin >> n;
	long long int *a = new long long int[n];
	for (int i = 0; i < n; i++) 
		cin >> a[i]; 

	switch (n)
	{
		case 1:
		{
			break;
		}
		case 2:
		{
			if (abs(a[1] - a[0]) == 1) 
				res = 2;
			break;
		}
		default:
		{
			for (int i = 1; i < n; i++) {
				long long d = a[i] - a[i - 1]; // for not calculating twice
				if (abs(d) == 1 && d == a[i + 1] - a[i])
					temp = temp == 1 ? 3 : temp + 1;
				else {
					if (temp >= res) {
						res = temp;
					}
					if (abs(a[i + 1] - a[i])  == 1|| abs(a[i] - a[i - 1]) == 1)
						temp = 2;
					else
						temp = 1;
				}
			}
			break;
		}
	}
	cout << res;
	return 0;
}