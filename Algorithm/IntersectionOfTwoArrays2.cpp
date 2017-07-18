#include "stdafx.h"
#include "IntersectionOfTwoArrays2.h"

// O(nlg2n)
std::vector<int> IntersectionOfTwoArrays2::solution1(std::vector<int>& nums1, std::vector<int>& nums2)
{
	std::vector<int> res;
	int i = 0, j = 0;

	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());

	while (i != nums1.size() && j != nums2.size())
	{
		if (nums1[i] == nums2[j])
		{
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

// Hash map solution O(n)
std::vector<int> IntersectionOfTwoArrays2::solution2(std::vector<int>& nums1, std::vector<int>& nums2)
{
	std::unordered_map<int, int> nums;
	std::vector<int> res;

	for (int i = 0; i < nums1.size(); ++i)
		nums[nums1[i]]++;

	// Can be more optimized for less space, see solution 3
	for (int i = 0; i < nums2.size(); ++i)
	{
		if (--nums[nums2[i]] >= 0)
			res.push_back(nums2[i]);
	}

	return res;
}

std::vector<int> IntersectionOfTwoArrays2::solution3(std::vector<int>& nums1, std::vector<int>& nums2)
{
	std::unordered_map<int, int> nums;
	std::vector<int> res;

	for (int i = 0; i < nums1.size(); ++i)
		nums[nums1[i]]++;

	for (int i = 0; i < nums2.size(); ++i)
	{
		if (nums.find(nums2[i]) != nums.end() && --nums[nums2[i]] >= 0)
			res.push_back(nums2[i]);
	}

	return res;
}