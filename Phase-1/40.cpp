/*
Given an array of length ‘N’, where each element denotes the position of a stall.
Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive.
To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that
the minimum distance between any two of them is as large as possible. Return the largest minimum distance.

Input :- 4 2 1 3 6
OutPut :- 5

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isPossible(vector<int> stalls, int n, int m, int mid)
{
    int cowsCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - lastPos >= mid) // this conditions means this is a possible solution
        {
            // Reach to second cow
            cowsCount++;
            // if no. of cows is placed return true
            if (cowsCount == m)
            {
                return true;
            }
            // Increase last position
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> stalls, int m)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;

    // end = maximum in vector - minimum in vector
    int end = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        end = max(end, stalls[i]);
    }

    int mid = start + (end - start) / 2;

    int ans = -1;
    while (start <= end)
    {
        if (isPossible(stalls, stalls.size(), m, mid))
        {
            ans = mid;
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

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    cout << aggressiveCows(stalls, cows);
    return 0;
}