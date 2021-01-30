#include <iostream>
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

int partition(int A[], int start, int end) {
	int i = start + 1;
	int piv = A[start];            //make the first element as pivot element.
	for (int j = start + 1; j <= end; j++) {
		/*rearrange the array by putting elements which are less than pivot
		on one side and which are greater that on other. */

		if (A[j] < piv) {
			swap(A[i], A[j]);
			i += 1;
		}
	}
	swap(A[start], A[i - 1]);  //put the pivot element in its proper place.
	return i - 1;                      //return the position of the pivot
}

int rand_partition(int A[], int start, int end) {
	//chooses position of pivot randomly by using rand() function .
	int random = start + rand() % (end - start + 1);

	swap(A[random], A[start]);        //swap pivot with 1st element.
	return partition(A, start, end);       //call the above partition function
}

void quickSort(int A[], int start, int end) {

	if (start < end) {
		//stores the position of pivot element
		int piv_pos = rand_partition(A, start, end);
		quickSort(A, start, piv_pos - 1);    //sorts the left side of pivot.
		quickSort(A, piv_pos + 1, end); //sorts the right side of pivot.
	}
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = 0, r = n-1;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	quickSort(a, l, r);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	

	delete[] a;
	return 0;
}