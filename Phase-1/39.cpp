/*
Given an array/list of length ‘N’, where the array/list
represents the boards and each element of the given array/list
represents the length of each board. Some ‘K’ numbers of painters are
available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this
job done of painting all the ‘N’ boards under a constraint that any
painter will only paint the continuous sections of boards.

For example :
2
4 2
5 5 5 5
4 2
10 20 30 40.

10
60

*/

// CODE LINK :- https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int isPossible(vector<int> nums, int n, int m, int mid)
{
    int painterCount = 1;
    int paint = 0;

    for (int i = 0; i < n; i++)
    {
        if (paint + nums[i] <= mid)
        {
            paint += nums[i];
        }
        else
        {
            painterCount++;
            if (painterCount > m || nums[i] > mid)
            {
                return false;
            }
            paint = nums[i];
        }
    }
    return true;
}

int paintersPartition(vector<int> arr, int m)
{
    int start = 0;
    int end = accumulate(arr.begin(), arr.end(), 0);
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (isPossible(arr, arr.size(), m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    vector<int> nums = {5, 5, 5, 5};
    int painters = 2;
    cout << paintersPartition(nums, painters);
    return 0;
}