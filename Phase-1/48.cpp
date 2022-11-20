/*
SUM OF TWO ARRAYS

nums1 = {1,2,3,4}
nums2 = {1,2,3,4}
output = {2,4,6,8}

nums1 = {9,9,9}
nums2 = {9,9,9}
output = {1,0,0,0}
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> nums1 = {1, 2, 3, 4};
    int n = nums1.size();
    vector<int> nums2 = {1, 2, 3, 4};
    int m = nums2.size();

    int i = n - 1;
    int j = m - 1;

    vector<int> ans;
    int carry = 0;

    // Handling equal elements of nums1 and nums2
    while (i >= 0 && j >= 0)
    {
        int val1 = nums1[i];
        int val2 = nums2[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    // Handling if remaining in nums1
    while (i >= 0)
    {
        int sum = nums1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    // Handling if remaining in nums2
    while (j >= 0)
    {
        int sum = nums2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // Handling if carry is remaining
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    //
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    return 0;
}