/*
@ Unique Number of Occurrences

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true


Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// LINK :- https://leetcode.com/problems/unique-number-of-occurrences/

bool uniqueOccurrences(vector<int> &arr)
{

    // Inserting elements and its count to map i.e { 1:3, 2:2, 3:1}.
    map<int, int> mp;
    for (auto num : arr)
    {
        mp[num]++;
    }

    // Making another map for frequency
    map<int, int> fr;
    for (auto count : mp)
    {
        fr[count.second]++;
    }

    // fr map will be like {1:1,2:1,3:1}.Finally now check for frequency value if greater than equal to 1. then return ans false else return true outside the loop.
    for (auto result : fr)
    {
        if (result.second > 1)
        {
            return 0;
        };
    }

    return 1;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1, 1, 3};
    cout << uniqueOccurrences(nums1);

    cout << endl;

    vector<int> nums2 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << uniqueOccurrences(nums2);

    cout << endl;

    vector<int> nums3 = {1, 2};
    cout << uniqueOccurrences(nums3);

    return 0;
}
