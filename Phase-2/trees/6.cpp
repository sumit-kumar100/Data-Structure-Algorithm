/*
//@ Balanced Binary Tree

Input: root = [3,9,20,null,null,15,7]
Output: true

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

CODE LINK : https://leetcode.com/problems/balanced-binary-tree/description/
*/
#include <iostream>
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
    // Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.first = (left.first && right.first && diff) ? true : false;
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }

public:
    // approach - 1
    bool isBalancedFastApproach(TreeNode *root)
    {
        return isBalancedFast(root).first;
    }

    // approach - 2
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        return (left && right && diff) ? true : false;
    }
};