#include "stdafx.h"
#include "QuickSort.h"

void QuickSort::quickSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int pivot = partition(arr, l, r);

		quickSort(arr, l, pivot - 1);
		quickSort(arr, pivot + 1, r);
	}
}

int QuickSort::partition(int arr[], int l, int r)
{
	int i = l - 1; // index of smaller elements
	int j = 0;
	int pivot = arr[r];

	for (j = l; j < r; ++j)
	{
		if (arr[j] < pivot)
		{
			++i;

			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}

	arr[r] = arr[i + 1];
	arr[i + 1] = pivot;

	return i + 1;
}