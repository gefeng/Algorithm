#include "stdafx.h"
#include "MergeSort.h"

void MergeSort::mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void MergeSort::merge(int arr[], int l, int m, int r)
{ 
	int i = l, j = m + 1, k = 0;

	int* temp = (int*)malloc(sizeof(int) * (r - l + 1));

	for (k = 0; k < (r - l + 1); ++k)
	{
		if(j > r || arr[i] < arr[j])
		{
			temp[k] = arr[i];
			++i;
		}
		else if (i > m || arr[j] < arr[i])
		{
			temp[k] = arr[j];
			++j;
		}
	}

	for (k = 0; k < (r - l + 1); ++k)
	{
		arr[l + k] = temp[k];
	}

	free(temp);
}

/*void MergeSort::mergeSortSln(std::vector<int> arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - 1) / 2;
		mergeSortSln(arr, l, m);
		mergeSortSln(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void MergeSort::merge(int arr[], int l, int m, int r)
{
	int tempArr1Size = m - l + 1;
	int tempArr2Size = r - m;

	int i, j, k = 0;

	int L[5], R[5];

	for (i = 0; i < tempArr1Size; ++i)
	{

	}

	for (i = 0; i < tempArr2Size; ++i)
	{
		
	}
}*/