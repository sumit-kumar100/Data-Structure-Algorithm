/*
@ K Sum Paths

Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.


Example 1:

Input:
Tree =
          1
        /   \
       2     3
K = 3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
Example 2:

Input:
Tree =
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5
        /   / \     \
       1   1   2     6
K = 5
Output: 8
Explanation:
The following paths sum to K.
3 2
3 1 1
1 3 1
4 1
1 -1 4 1
-1 4 2
5
1 -1 5
*/

// CODE LINK : https://leetcode.com/problems/path-sum-iii/description/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void solve(TreeNode *root, int k, int &count, vector<int> &path)
    {
        // base case
        if (root == NULL)
        {
            return;
        }
        // add current data to path
        path.push_back(root->val);

        // left and right recursive calls
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        // check for k sum
        long int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }

        // delete current data from path i.e, backtracking
        path.pop_back();
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int count = 0;
        vector<int> path;
        solve(root, targetSum, count, path);
        return count;
    }
};