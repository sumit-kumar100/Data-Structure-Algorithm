
/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void printVector(vector<int> &nums)
{
    cout << "printing the Vector " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

// LINK :- https://leetcode.com/problems/sort-colors/
void sortColors(vector<int> &nums)
{

    int i = 0, j = nums.size() - 1;

    while (i < nums.size() && j >= i)
    {

        if (i == j)
        {
            i++;
            j = nums.size() - 1;
        }
        else if (nums[i] > nums[j])
        {
            swap(nums[i], nums[j]);
        }
        else
        {
            j--;
        }
    }
}

// LINK :- https://www.codingninjas.com/codestudio/problems/sort-array-of-0s-and-1s_2656186
void sortOne(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        while (nums[left] == 0 && left < right)
        {
            left++;
        }
        while (nums[right] == 1 && left < right)
        {
            right--;
        }

        if (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    vector<int> num1 = {1, 1, 0, 0, 0, 0, 1, 0};

    sortOne(num1);

    printVector(num1);

    vector<int> num2 = {2, 0, 2, 1, 1, 0};

    sortColors(num2);

    printVector(num2);

    return 0;
}