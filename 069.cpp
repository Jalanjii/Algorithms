#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, index = -1, res = -1, length = 0, max_length = 0;
	bool flipped = false;

	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (flipped) {
				flipped = false;
				length = 0;
				if (i + 1 < n && a[i + 1] == 1)
					i = index;
			}
			else {
				flipped = true;
				index = i;
			}
		}
		++length;
		if (length > max_length) {
			res = index;
			max_length = length;
		}
	}

	cout << res + 1;

	delete[] a;
	return 0;
}

-----------

#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, index = -1, res = -1, length = 0, max_length = 0;
	bool flipped = false;

	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (flipped) {
				flipped = false;
				length = 0;
				if (i + 1 < n && a[i + 1] == 1)
					i = index;
			}
			else {
				flipped = true;
				index = i;
			}
		}
		++length;
		if (length > max_length) {
			res = index;
			max_length = length;
		}
	}

	cout << res + 1;

	delete[] a;
	return 0;
}

------------
#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	bool flipped = false;
	int index = -1; 
	int res = -1; 
	int length = 0;
	int max_length = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (flipped) {
				flipped = false;
				length = -1;
				if (i + 1 < n && a[i + 1] == 1)
					i = index;
			}
			else {
				flipped = true;
				index = i;
			}
		}
		++length;
		if (length > max_length) {
			res = index;
			max_length = length;
		}	
	}

	cout << res + 1;
	
	delete[] a;
	return 0;
}

------------
#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	bool flipped = false;
	int index = -1; 
	int res = -1; 
	int length = 0;
	int max_length = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (flipped) {
				flipped = false;
				length = -1;
				if (i + 1 < n && a[i + 1] == 1)
					i = index;
			}
			else {
				flipped = true;
				index = i;
			}
		}
		++length;
		if (length > max_length) {
			res = index;
			max_length = length;
		}	
	}

	cout << res + 1;
	
	delete[] a;
	return 0;
}