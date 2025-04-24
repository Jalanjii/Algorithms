#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

int minCoins(long long int a[], int n, long long int s) {

	int *res = new int[s+1];

	res[0] = 0;

	for (int i = 1; i <= s; i++)
		res[i] = INT_MAX;

	for (int i = 1; i <= s; i++)
	{
		for (int j = 0; j < n; j++)
			if (a[j] <= i)
			{
				long long int sub_ind = i - a[j];
				int sub_res = res[sub_ind];
				if (sub_res != INT_MAX && sub_res + 1 <= res[i]) {	
					res[i] = sub_res + 1;
				}
					
			}
	}
	return res[s];

}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, res;
	long long int s;
	cin >> n >> s;

	long long int *a = new long long int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	res = minCoins(a, n, s);

	if (res != INT_MAX)
		cout << res;
	else
		cout << -1;

	delete[] a;
	return 0;
}
-----------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cmath>
#include <climits>
//#include <string>
//#include <algorithm>

using namespace std;

int minCoins(long long int a[], int n, long long int s)
{
	bool flag = false;

	int *res = new int[s+1];

	res[0] = 0;

	for (int i = 1; i <= s; i++)
		res[i] = INT_MAX;

	for (int i = 1; i <= s; i++)
	{
		for (int j = 0; j < n; j++)
			if (a[j] <= i)
			{
				long long int sub_ind = i - a[j];
				int sub_res = res[sub_ind];
				if (sub_res != INT_MAX && sub_res + 1 <= res[i]) {	
					res[i] = sub_res + 1;
				}
					
			}
	}
	return res[s];

}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, res;
	long long int s;
	cin >> n >> s;

	long long int *a = new long long int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	res = minCoins(a, n, s);

	if (res != INT_MAX)
		cout << res;
	else
		cout << -1;

	delete[] a;
	return 0;
}