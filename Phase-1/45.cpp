/*
@ Move Zeroes
Add to List

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

*/

#include <istream>
#include <vector>
using namespace std;

// Brute Force Solution
void moveZeroes(vector<int> &nums)
{

    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (nums[j] == 0)
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

// OPTIMISED SOLUTION

void moveZeroes(vector<int> &nums)
{

    int nonZero = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[nonZero]);
            nonZero++;
        }
    }
}