#include <iostream>  
//#include <algorithm>
//#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, r = 0, c = 0, e = 1;
	bool tag = false;

	cin >> n;

	int **m = new int*[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n]; // No need to initialize to 0
	}


	for (int i = 1; i <= n*n; i++) {
		m[r][c] = i;
		if (tag) { //manages the right triangle of the square (x=y)

			if (c == n - 1) {
				c = 1 + e;
				r = n - 1;
				e++; //e manages the correct landing of c after c = n -1
			}
			else {
				r--;
				c++;
			}
		}
		else { // manages the first left triangle of the square (x=y)
			if (r == 0) {
				c = 0;
				r = r + e;
				e++; // e manages the correct landing of r after r = 0
			}
			else {
				r--;
				c++;
			}
			if (c == n - 1) {
				tag = true;
				e = 0;
			}

		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;


	return 0;
}
----------------
#include <iostream>  
//#include <algorithm>
//#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, r = 0, c = 0, e = 1;
	bool tag = false;

	cin >> n;

	int **m = new int*[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			m[i][j] = 0;
		}
	}


	for (int i = 1; i <= n*n; i++) {
		m[r][c] = i;
		if (tag) { //manages the right triangle of the square (x=y)

			if (c == n - 1) {
				c = 1 + e;
				r = n - 1;
				e++; //e manages the correct landing of c after c = n -1
			}
			else {
				r--;
				c++;
			}
		}
		else { // manages the first left triangle of the square (x=y)
			if (r == 0) {
				c = 0;
				r = r + e;
				e++; // e manages the correct landing of r after r = 0
			}
			else {
				r--;
				c++;
			}
			if (c == n - 1) {
				tag = true;
				e = 0;
			}

		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;


	return 0;
}
-------------
#include <iostream>  
#include <algorithm>
//#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, r = 0, c = 0, e = 1;
	bool tag = false;

	cin >> n;
	int k = n*n;

	int **m = new int*[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			m[i][j] = 0;
		}
	}
	

	for (int i = 1; i <= k; i++) {

		if (tag) { //manages the right triangle of the square (x=y)
			if (i == k) {
				m[n-1][n-1] = i;
				break;
			}
			
			m[r][c] = i;
			if (c == n-1) {
				c = 1 + e;
				r = n - 1;
				e++; //e manages the correct landing of c after c = n -1
			}
			else {
				r--;
				c++;
			}
		}
		else { // manages the first left triangle of the square (x=y)
			m[r][c] = i;
			if (r == 0) {
				c = 0;
				r = r + e;
				e++; // e manages the correct landing of r after r = 0
			}
			else {
				r--;
				c++;
			}
			if (c == n - 1) {
				tag = true;
				e = 0;
			}
				
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;


	return 0;
}
------------
#include <iostream>  
#include <algorithm>
//#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, r = 0, c = 0, e = 1;
	bool tag = false;

	cin >> n;
	int k = n*n;

	int **m = new int*[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			m[i][j] = 0;
		}
	}
	

	for (int i = 1; i <= k; i++) {

		if (tag) {
			if (i == k) {
				m[n-1][n-1] = i;
				break;
			}
			
			m[r][c] = i;
			if (c == n-1) {
				c = 1 + e;
				r = n - 1;
				e++;
			}
			else {
				r--;
				c++;
			}
		}
		else {
			m[r][c] = i;
			if (r == 0) {
				c = 0;
				r = r + e;
				e++;
			}
			else {
				r--;
				c++;
			}
			if (c == n - 1) {
				tag = true;
				e = 0;
			}
				
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;


	return 0;
}