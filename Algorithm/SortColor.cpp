#include "stdafx.h"
#include "SortColor.h"

// Two-pass algorithm O(n)
void SortColor::solution1(std::vector<int>& nums)
{
	int redCounter = 0, greenCounter = 0, blueCounter = 0;

	for (auto num : nums)
	{
		switch (num)
		{
		case 0:
			++redCounter;
			break;
		case 1:
			++greenCounter;
			break;
		case 2:
			++blueCounter;
			break;
		default:
			break;
		}
	}

	nums.clear();

	for (int i = 0; i < redCounter; ++i)
		nums.push_back(0);
	for (int i = 0; i < greenCounter; ++i)
		nums.push_back(1);
	for (int i = 0; i < blueCounter; ++i)
		nums.push_back(2);
}

// One-pass algorithm O(n)
void SortColor::solution2(std::vector<int>& nums)
{
	int redIndex = 0, greenIndex = 0, blueIndex = nums.size() - 1;
	int temp;

	while (greenIndex <= blueIndex)
	{
		if (nums[greenIndex] == 1)
		{
			++greenIndex;
		}
		else if (nums[greenIndex] == 0)
		{
			temp = nums[greenIndex];
			nums[greenIndex] = nums[redIndex];
			nums[redIndex] = temp;

			++redIndex;
			++greenIndex;
		}
		else
		{
			temp = nums[greenIndex];
			nums[greenIndex] = nums[blueIndex];
			nums[blueIndex] = temp;

			--blueIndex;
		}
	}
}