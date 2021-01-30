#include <iostream>
//#include <cmath>
//#include <climits>
//#include <algorithm>

using namespace std;

int power(int a) {
	int p = a*a;
	return  p;
}

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a; cin >> a;
	cout << power(a);
	
	return 0;
}
------
#include <iostream>
#include <cmath>
//#include <climits>
//#include <algorithm>

using namespace std;

int power(int a) {
	int p = a*a;
	return p;
}

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a; cin >> a;
	cout << power(a);

	return 0;
}