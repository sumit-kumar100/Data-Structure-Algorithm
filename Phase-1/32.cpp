/*
@ Two Sum
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


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// LINK :- https://leetcode.com/problems/two-sum/

// Time complexity will be O(n^2)
vector<int> twoSum(vector<int> &nums, int target)
{

    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }

    return ans;
}

// Time complexity will be O(n log n)
vector<int> twoSum2(vector<int> &nums, int target)
{

    map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i)
    {
        int diff = target - nums[i];
        if (mp.find(diff) != mp.end())
        {
            return {i, mp[diff]};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};

    int target = 13;

    vector<int> result1 = twoSum(nums, target);

    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << " ";
    }

    cout << endl;

    vector<int> nums2 = {3, 2, 4};

    int target2 = 6;

    vector<int> result2 = twoSum2(nums2, target2);

    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }

    return 0;
}