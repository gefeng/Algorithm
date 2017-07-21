#include "stdafx.h";
#include "LargestNumber.h"

// O(nlog2n)
std::string solution(std::vector<int>& nums)
{
	std::vector<std::string> numsInString;
	std::string res;
	
	for (auto n : nums)
	{
		numsInString.push_back(std::to_string(n));
	}

	std::sort(numsInString.begin(), numsInString.end(), [](std::string s1, std::string s2) -> bool { return s1 + s2 > s2 + s1; });

	for (auto n : numsInString)
	{
		res += n;
	}

	while (res[0] == '0' && res.size() > 1)
	{
		res.erase(0, 1);
	}

	return res;
}