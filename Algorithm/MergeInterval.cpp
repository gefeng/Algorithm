#include "stdafx.h"
#include "MergeInterval.h"

// O(nlog2n)
std::vector<Interval> solution1(std::vector<Interval>& intervals)
{
	std::vector<Interval> res;
	
	std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) -> bool { return a.start < b.start; });

	if (intervals.size() == 1)
	{
		res.push_back(intervals[0]);
	}
	else if(intervals.size() > 1)
	{
		Interval temp = intervals[0];

		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i].start <= temp.end)
			{
				int end = temp.end > intervals[i].end ? temp.end : intervals[i].end;
				temp = Interval(temp.start, end);
			}
			else
			{
				res.push_back(temp);
				temp = intervals[i];
			}
		}

		res.push_back(temp); // add last element
	}

	return res;
}

// Improvement
std::vector<Interval> solution2(std::vector<Interval>& intervals)
{
	std::vector<Interval> res;

	if (intervals.size() == 0)
		return res;

	std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start; });

	res.push_back(intervals[0]);

	for (int i = 1; i < intervals.size(); ++i)
	{
		if (res.back().end >= intervals[i].start)
			res.back().end = std::max(res.back().end, intervals[i].end);
		else
			res.push_back(intervals[i]);
	}

	return res;
}