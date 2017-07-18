#include "stdafx.h";
#include "ValidAnagram.h"

// O(N)
bool ValidAnagram::solution1(std::string s, std::string t)
{
	if (s.length() != t.length())
		return false;

	int n = s.length();

	int counts[26] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		counts[s[i] - 'a']++;
		counts[t[i] - 'a']--;
	}

	for (int i = 0; i < 26; ++i)
	{
		if(counts[i] != 0)
			return false;
	}
	
	return true;
}

// if accept unicode, use hash table O(N)
bool ValidAnagram::solution2(std::string s, std::string t)
{
	if (s.length() != t.length())
		return false;

	std::unordered_map<char, int> counts;
	int n = s.length();

	for (int i = 0; i < n; ++i)
	{
		counts[s[i]]++;
		counts[t[i]]--;
	}

	for (int i = 0; i < counts.size(); ++i)
	{
		if (counts[i])
			return false;
	}

	return true;
}

// O(Nlog2N)
bool ValidAnagram::solution3(std::string s, std::string t)
{
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	if (s != t)
		return false;

	return true;
}