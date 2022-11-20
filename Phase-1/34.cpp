/*
@ Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
#include <iostream>
#include <vector>
using namespace std;

// CODE LINK :- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

int leftMostOccurence(vector<int> &nums, int key)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    // Here, this is only termination conditions.
    while (start <= end)
    {
        // Storing index in ans & (mid=end-1), for finding left most occurence.
        if (nums[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (key > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int rightMostOccurence(vector<int> &nums, int key)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    // Here, this is only termination conditions.
    while (start <= end)
    {
        // Storing index in ans & (mid=end-1), for finding left most occurence.
        if (nums[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (key > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{

    cout << "The left most occurence of target number is :- ";
    cout << leftMostOccurence(nums, 8);
    cout << endl;
    cout << "The right most occurence of target number is :- ";
    cout << rightMostOccurence(nums, 8);
    return nums;
}

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 9};
    int target = 8;

    // USING BINARY SEARCH APPROACH
    searchRange(arr, target);

    // MY CUSTOM LOGIN WITH BINARY SEARCH USING TWO POINTERS APPROACH.

    int left = 0;
    int right = arr.size() - 1;
    int left_ans = -1, right_ans = -1;
    while (left <= right)
    {
        if (arr[left] == target)
        {
            left_ans = left;
            break;
        }
        left++;
    }
    while (left <= right)
    {
        if (arr[right] == target)
        {
            right_ans = right;
            break;
        }
        right--;
    }

    cout << endl;
    cout << "Left Most Occurence is : " << left_ans;
    cout << endl;
    cout << "Right most Occurence is : " << right_ans;
    return 0;
}