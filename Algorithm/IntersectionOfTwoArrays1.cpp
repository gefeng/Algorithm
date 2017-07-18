#include "stdafx.h"
#include "IntersectionOfTwoArrays1.h"

// O(nlg2n)
std::vector<int> IntersectionOfTwoArrays1::solution1(std::vector<int>& nums1, std::vector<int>& nums2)
{
	int i = 0, j = 0;

	std::vector<int> res;

	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());

	while (i != nums1.size() && j != nums2.size())
	{
		if (nums1[i] == nums2[j])
		{
			if (res.empty() || res[res.size() - 1] != nums1[i])
				res.push_back(nums1[i]);
			
			++i;
			++j;
		}
		else if (nums1[i] < nums2[j])
			++i;
		else
			++j;
	}

	return res;
}

// O(n)
std::vector<int> IntersectionOfTwoArrays1::solution2(std::vector<int>& nums1, std::vector<int>& nums2)
{
	std::unordered_set<int> nums(nums1.begin(), nums1.end());
	std::vector<int> res;

	for (int i = 0; i < nums2.size(); ++i)
	{
		if (nums.count(nums2[i]))
		{
			res.push_back(nums2[i]);
			nums.erase(nums2[i]);
		}
	}

	return res;
}