#include <iostream>
//#include <cmath>
//#include <climits>
#define SIZE 1000

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//using indexes for range 0-999 by setting size to 1000
	bool in[SIZE]{};
	int n;
	cin >> n;

	for (int num, i = 0; i < n; i++) { cin >> num;
		if (!in[num]) { cout << num << " "; in[num] = true; }
	}
	return 0;
}

--------------
#include <iostream>
//#include <cmath>
//#include <climits>
#define SIZE 999

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//using indexes for range 0-999
	bool in[SIZE] = {false};
	int n;
	cin >> n;

	for (int num, i = 0; i < n; i++) { cin >> num;
		if (!in[num]) { cout << num << " "; in[num] = true; }
	}
	return 0;
}
