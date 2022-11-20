/*
@ Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.



Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// LEETCODE QUESTION . IT DOESN'T INCLUDE XORING NUMS WITH ITSELF IN A RANGE.

// LINK :- https://leetcode.com/problems/find-the-duplicate-number/

int findDuplicate(vector<int> &nums)
{

    map<int, int> mp;

    // Adding element ans its frequecny in map
    for (auto num : nums)
    {
        mp[num]++;
        if (mp[num] > 1)
        {
            return num;
        }
    }

    return 0;
}

/*
You are given an array ‘ARR’ of size ‘N’ containing each number between 1
and ‘N’ - 1 at least once. There is a single integer value that is present
in the array twice. Your task is to find the duplicate integer value present in the array.

Consider ARR = [1, 2, 3, 4, 4],
the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.

NOTE :- A duplicate number is always present in the given array.
*/

// LINK :- https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397

int findDuplicateXoring(vector<int> &nums)
{
    int ans = 0;

    // XOR ing all the element of array.
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }

    // XOR ing [1 - nums.size()-1]
    for (int i = 1; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }

    return ans;
}