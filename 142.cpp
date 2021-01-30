#include <iostream> //Stable MergeSort//
//#include <cmath>
//#include <climits>
//#include <string>
#include <algorithm>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	int *L = new int[n1], *R = new int[n2];


	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])//stability guaranteed,
						 //If two elements are equal, 
						 //the element on the right will not be
						 //put first in the merged array 
						 //which does not change the original ordering.
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
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

	mergeSort(a, l, r);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	

	delete[] a;
	return 0;
}