#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, b1, b2, rem, k, i, j, t;
	int a[30]; j = 0; t = 0;

	cin >> n >> b1 >> b2;
	k = int(log10(n)) + 1; 

	//converts number of b1 to an intermediate base 10
	for (i = 0; i < k; i++) { 
		t += (n % 10)*pow(b1, i);
		n /= 10;
	}
	//converts number of base 10 to b2
	if (t == 0) { cout << 0; }
	while (t)
	{
		rem = t % b2;
		a[j++] = rem;
		t /= b2;
	}
	for (j = j - 1; j >= 0; j--)
	{
		cout << a[j];
	}
	return 0;
}

-------------

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, b1, b2, rem, k, i, j, t;
	int a[30]; j = 0; t = 0;

	cin >> n >> b1 >> b2;
	k = int(log10(n)) + 1; 

	//converts to an intermediate base 10
	for (i = 0; i < k; i++) { 
		t += (n % 10)*pow(b1, i);
		n /= 10;
	}
	
	if (t == 0) { cout << 0; }
		
	
	while (t)
	{
		rem = t % b2;
		a[j++] = rem;
		t /= b2;
	}

	for (j = j - 1; j >= 0; j--)
	{
		cout << a[j];
	}

	return 0;
}