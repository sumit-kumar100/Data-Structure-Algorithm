/*
@ Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

*/
#include <iostream>
#include <vector>
using namespace std;

// CODE LINK :- https://leetcode.com/problems/search-in-rotated-sorted-array/

// FINDING PIVOT POINT IN AN ELEMENT.
int findPivot(vector<int> &nums, int n)
{
    int start = 0;
    int end = n;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (nums[mid] >= nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
// NORMAL BINARY SEARCH
int binarySearch(vector<int> &arr, int start, int end, int key)
{

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return -1;
}
// Search in Rotated Sorted Array
int search(vector<int> &nums, int target)
{

    int n = nums.size() - 1;
    int pivot = findPivot(nums, n);
    if (target >= nums[pivot] && target <= nums[n])
    {
        return binarySearch(nums, pivot, n, target);
    }
    else
    {
        return binarySearch(nums, 0, pivot - 1, target);
    }
    return -1;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search(nums, target);
    
    return 0;
}
