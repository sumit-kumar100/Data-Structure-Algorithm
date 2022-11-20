/*
Merge sorted arrray 
nums1 = {1, 3, 5, 7, 8, 9};
m = 6;
nums2 = {2, 4, 6};
n = 3;

Output = {1, 2, 3, 4, 5, 6, 7, 8, 9}

*/

#include <iostream>
#include <vector>
using namespace std;

void printNums(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    vector<int> ans;

    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }

    while (i < m)
    {
        ans.push_back(nums1[i]);
        i++;
    }

    while (j < n)
    {
        ans.push_back(nums2[j]);
        j++;
    }

    printNums(ans);

    return 0;
}