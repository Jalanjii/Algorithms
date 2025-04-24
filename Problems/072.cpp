#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void k_combinations(vector<int> &elements, string out, int n, int k) {

	if (k > n)
		return;

	if (k == 0) {
		cout << out << endl;
		return;
	}

	for (int i = n - 1; i >= 0; i--) {

		k_combinations(elements, to_string(elements[i]) + " " + out, i, k - 1);
		while (elements[i] == elements[i - 1])
			i--;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n;

	vector<int> elements(n);
	for (int i = 0; i < n; i++)
		cin >> elements[i];
	cin >> k;

	sort(elements.begin(), elements.end());
	k_combinations(elements, "", n, k);

	return 0;
}
-----------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void k_combinations(vector<int> &elements, string out, int n, int k) {

	if (k > n)
		return;

	if (k == 0) {
		cout << out << endl;
		return;
	}

	for (int i = n - 1; i >= 0; i--) {

		k_combinations(elements, to_string(elements[i]) + " " + out, i, k - 1);
		while (elements[i] == elements[i - 1])
			i--;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n;

	vector<int> elements(n);
	for (int i = 0; i < n; i++)
		cin >> elements[i];
	cin >> k;

	sort(elements.begin(), elements.end());
	k_combinations(elements, "", n, k);

	return 0;
}
----------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int k_combinations(vector<int> &elements, string out, int n, int k) {
    
    if (k > n)
        return 0;

    if (k == 0) {
        cout << out << endl;
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {

        k_combinations(elements, to_string(elements[i]) + " " + out, i, k - 1);
        while (elements[i] == elements[i - 1])
            i--;
    }
    return 0;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n;
    
    vector<int> elements(n);
    for (int i = 0; i < n; i++)
        cin >> elements[i];
    cin >> k;
    
    sort(elements.begin(), elements.end()); 
    k_combinations(elements, "", n, k);
    
    return 0;
}

---------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void k_combinations(vector<int> &elements, string out, int n, int k) {
    
	if (k > n)
		return;

	if (k == 0) {
		cout << out << endl;
		return;
	}

	for (int i = n - 1; i >= 0; i--) {

		k_combinations(elements, to_string(elements[i]) + " " + out, i, k - 1);
		while (elements[i] == elements[i - 1])
			i--;
	}
}

int main() {

 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
	
    int n, k;
    cin >> n;
    
    vector<int> elements(n);
    for (int i = 0; i < n; i++)
        cin >> elements[i];
    cin >> k;
    
    sort(elements.begin(), elements.end()); 
    k_combinations(elements, "", n, k);
    
	return 0;
}