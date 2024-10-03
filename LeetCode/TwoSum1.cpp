#include <vector>
#include <algorithm>


/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/


class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::vector<int> SortNums = nums;
		std::sort(SortNums.begin(), SortNums.end());
		std::vector<int> result{};



		int sum = SortNums.front();
		if (SortNums.front() + SortNums.back() == target) // 0 + 100 = target
		{
			auto IteratorFirstNum = std::find(nums.begin(), nums.end(), SortNums.front());
			auto IteratorSecondNum = std::find(nums.begin(), nums.end(), SortNums.back());

			return std::vector<int>{ (int)std::distance(nums.begin(), IteratorFirstNum), (int)std::distance(nums.begin(), IteratorSecondNum) };
		}
		else
		{
			if (SortNums.front() + SortNums[SortNums.size() / 2] >= target) // 0 - 50
			{
				if (SortNums.front() + SortNums[SortNums.size() / 2] == target) // 0 + 50 = target
				{
					auto IteratorFirstNum = std::find(nums.begin(), nums.end(), SortNums.front());
					auto IteratorSecondNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size() / 2]);
					return std::vector<int>{ (int)std::distance(nums.begin(), IteratorFirstNum), (int)std::distance(nums.begin(), IteratorSecondNum) };
				}
				else
				{
					if (SortNums.front() + SortNums[SortNums.size() / 4] >= target) // 0 - 25
					{
						if (SortNums.front() + SortNums[SortNums.size() / 4] == target) // 0 + 25 = target
						{
							auto IteratorFirstNum = std::find(nums.begin(), nums.end(), SortNums.front());
							auto IteratorSecondNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size() / 4]);
							return std::vector<int>{ (int)std::distance(nums.begin(), IteratorFirstNum), (int)std::distance(nums.begin(), IteratorSecondNum) };
						}
						else
						{
							// handle 0 - 25
						}
					}
					else // 26-50
					{
						if (SortNums[SortNums.size() / 4 + 1] + SortNums[SortNums.size() / 2] == target) // 26 + 50 = target
						{
							auto IteratorFirstNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size() / 4 + 1]);
							auto IteratorSecondNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size() / 2]);
							return std::vector<int>{ (int)std::distance(nums.begin(), IteratorFirstNum), (int)std::distance(nums.begin(), IteratorSecondNum) };
						}
						else
						{
							// handle 26 - 50
						}
					}
				}
			}
			else // 51 - 100
			{

				if (SortNums[SortNums.size() / 2 + 1] + SortNums[SortNums.size()] == target) // 51 + 100 = target
				{
					auto IteratorFirstNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size() / 2 + 1]);
					auto IteratorSecondNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size()]);
					return std::vector<int>{ (int)std::distance(nums.begin(), IteratorFirstNum), (int)std::distance(nums.begin(), IteratorSecondNum) };
				}
				else
				{ 
					if (SortNums[SortNums.size() / 2 + 1] + SortNums[SortNums.size() / 4 * 3] >= target) // 51 - 75
					{
						if (SortNums[SortNums.size() / 2 + 1] + SortNums[SortNums.size() / 4 * 3] == target) // 51 + 75 = target
						{
							auto IteratorFirstNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size() / 2 + 1]);
							auto IteratorSecondNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size() / 4 * 3]);
							return std::vector<int>{ (int)std::distance(nums.begin(), IteratorFirstNum), (int)std::distance(nums.begin(), IteratorSecondNum) };
						}
						else
						{
							// handle 51 - 75
						}
						


					}
					else // 76 - 100
					{
						if (SortNums[SortNums.size() / 4 * 3 + 1] + SortNums.size() == target) // 76 + 100 = target
						{
							auto IteratorFirstNum = std::find(nums.begin(), nums.end(), SortNums[SortNums.size() / 4 * 3 + 1]);
							auto IteratorSecondNum = std::find(nums.begin(), nums.end(), SortNums.size());
							return std::vector<int>{ (int)std::distance(nums.begin(), IteratorFirstNum), (int)std::distance(nums.begin(), IteratorSecondNum) };
						}
						else
						{
							// handle 76-100
						}
					}
				}

			}
		}

	}
};