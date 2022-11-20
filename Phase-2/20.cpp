/*
@Permutations

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

*/

// CODE LINK : https://leetcode.com/problems/permutations

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permutation(string str, int index, vector<string> &ans)
{
    if (index >= str.size())
    {
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.size(); i++)
    {
        swap(str[index], str[i]);
        permutation(str, index + 1, ans);
    }
}

int main()
{
    string str = "abc";
    vector<string> ans;
    permutation(str, 0, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}

// Array permuation
void permutation(vector<int> nums, int index, vector<vector<int>> &ans)
{
    // Base Case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        permutation(nums, index + 1, ans);

        // backtrack
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    permutation(nums, 0, ans);
    return ans;

}