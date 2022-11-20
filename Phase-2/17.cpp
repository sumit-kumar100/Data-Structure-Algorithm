/*
78. Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.


*/

// CODE LINK : https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, int index, vector<int> output, vector<vector<int>> &ans)
{
    // Base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Recursion tu exclude part sambhal le
    solve(nums, index + 1, output, ans);

    // Recursion ab tu include part sambhal le
    int element = nums[index];
    output.push_back(element);
    solve(nums, index + 1, output, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    // Kar de bhai solve
    solve(nums, index, output, ans);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    subsets(nums);
    return 0;
}