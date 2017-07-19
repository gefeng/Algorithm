// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntersectionOfTwoArrays1.h"
#include "IntersectionOfTwoArrays2.h"
#include "HeapSort.h"
#include "MergeSort.h"


int main()
{
	//IntersectionOfTwoArrays1 problem;
	/*IntersectionOfTwoArrays2 problem;

	std::vector<int> nums1 = { 1, 2, 2, 1 };
	std::vector<int> nums2 = { 2, 2 };
	
	std::vector<int> res = problem.solution2(nums1, nums2);

	for (int i = 0; i < res.size(); ++i)
	{
		std::cout << res[i] << std::endl;
	}*/

	HeapSort hs;
	MergeSort ms;

	//int arr[] = { 4, 1, 3, 9, 8, 10, 5, 21, 12, 23, 17, 27, 8, 2, 3, 4 };
	int arr[] = { 4, 1, 3, 9 };

	//hs.buildMaxHeap(arr, 16);

	//hs.heapSort(arr, 16);
	ms.mergeSort(arr, 0, 3);

	for (int i = 0; i < 4; ++i)
	{
		std::cout << arr[i] << std::endl;
	}

	system("pause");
	return 0;
}

