#include <iostream>
//#include <cmath>
//#include <climits>
#define SIZE 100001

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//using indexes for range 0-100000
	bool in[SIZE]{};
	int n; cin >> n;
	
	for (int num, i = 0; i < n; i++) {
		cin >> num;
		if (!in[num]) {in[num] = true; }
		else {
			cout << num; }
	}
	return 0;
}