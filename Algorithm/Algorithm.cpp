// Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntersectionOfTwoArrays1.h"
#include "IntersectionOfTwoArrays2.h"


int main()
{
	//IntersectionOfTwoArrays1 problem;
	IntersectionOfTwoArrays2 problem;

	std::vector<int> nums1 = { 1, 2, 2, 1 };
	std::vector<int> nums2 = { 2, 2 };
	
	std::vector<int> res = problem.solution2(nums1, nums2);

	for (int i = 0; i < res.size(); ++i)
	{
		std::cout << res[i] << std::endl;
	}

	system("pause");
	return 0;
}

