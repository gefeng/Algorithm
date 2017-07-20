#pragma once

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given[1, 3], [2, 6], [8, 10], [15, 18],
return[1, 6], [8, 10], [15, 18].
*/

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class MergeInterval
{
public:
	std::vector<Interval> solution1(std::vector<Interval>& intervals);
};