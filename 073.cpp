#include <iostream>
#include <algorithm>
//#include <cmath>
#include <string>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, maxlength = 1;

	cin >> n;

	string *a = new string[n];
	for (int i = 0; i < n; i++) { // inputs/determinning maximum length
		int lens;
		cin >> a[i];
		lens = a[i].length();
		if (lens > maxlength)
			maxlength = lens;//maxlength determined
	}

	for (int i = 0; i < n; i++) { // registerring original
								  // length of a given element
		string orglen, temp;
		orglen = to_string(a[i].length());
		temp = a[i];
		for (int j = 0; j <= maxlength; j++)//concatenating strings until
											// they get to maximum length,
											// roughly;
			a[i] += temp;// temp stores the original element
						 // s we don't make dupilcates 
						 //in the form a[i]+= a[i]
		a[i] = a[i].substr(0, maxlength + 1) + orglen;// we equalize the length of all
													  // element to the maximum length + 1
													  //add original length to the end so 
												    	//we know how to get our number
												    	// back for output.
	}

	sort(a, a + n);//simple sorting

	for (int i = n - 1; i >= 0; i--) {// we start from the end to get the biggest number.
		int c;
		string res;
		c = stoi(a[i].substr(maxlength + 1, int(log10(maxlength)) + 1));//we get that original length
																		// stored at the end
																		//This version is generalized 
																		//to any maximum of length
																		//if we put 2 instead of int(log10(maxlength)) + 1, then
																		//we algorithm works only when the maxlength <99

		res = a[i].substr(0, c);//we get out number back
		cout << res;//we output
	}

	delete[] a;
	return 0;
}
-----------------

#include <iostream>
#include <algorithm>
//#include <cmath>
#include <string>

using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, maxlength = 1;

	cin >> n;

	string *a = new string[n];
	for (int i = 0; i < n; i++) { // inputs/determinning maximum length
		int lens;
		cin >> a[i];
		lens = a[i].length();
		if (lens > maxlength)
			maxlength = lens;//maxlength determined
	}

	for (int i = 0; i < n; i++) { // registerring original length of a given element
		string orglen, temp;
		orglen = to_string(a[i].length());
		temp = a[i];
		for (int j = 0; j <= maxlength; j++)//concatenating strings until they get to maximum length, roughly;
			a[i] += temp;// temp stores the original element s we don't make dupilcates in the form a[i]+= a[i]
		a[i] = a[i].substr(0, maxlength + 1) + orglen;// we equalize the length of all element to the maximum length + 1
		//add original length to the end so we know how to get our number back for output.
	}

	sort(a, a + n);//simple sorting

	for (int i = n - 1; i >= 0; i--) {// we start from the end to get the biggest number.
		int c;
		string res;
		c = stoi(a[i].substr(maxlength + 1, int(log10(maxlength)) + 1));//we get that original length stored at the end
																		//This version is generalized to any maximum of length
																		//if we put 2 instead of int(log10(maxlength)) + 1, then
																		//we algorithm works only when the maxlength <99

		res = a[i].substr(0, c);//we get out number back
		cout << res;//we output
	}

	delete[] a;
	return 0;
}
