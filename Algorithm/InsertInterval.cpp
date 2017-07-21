#include "stdafx.h"
#include "InsertInterval.h"

// O(n)
std::vector<Interval> InsertInterval::solution(std::vector<Interval>& intervals, Interval newInterval)
{
	std::vector<Interval> res;
	std::vector<Interval>::iterator it;

	for (it = intervals.begin(); it != intervals.end(); ++it)
	{
		if (newInterval.end < (*it).start)
			break;
		else if (newInterval.start >(*it).end)
			res.push_back(*it);
		else
		{
			newInterval.start = std::min(newInterval.start, (*it).start);
			newInterval.end = std::max(newInterval.end, (*it).end);
		}
	}

	res.push_back(newInterval);

	for (; it != intervals.end(); ++it)
	{
		res.push_back(*it);
	}

	return res;
}