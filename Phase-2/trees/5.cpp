/*
@ Diameter of a binary tree
CODE LINK : https://leetcode.com/problems/diameter-of-binary-tree/description/
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
    pair<int, int> diameterFast(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        // recursive calls
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        // taking out answers from pairs
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second;

        // store answer and height in pair
        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(left.second, right.second) + 1;

        // return answer
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
    // approach 1
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = height(root->left) + height(root->right);

        int ans = max(opt1, max(opt2, opt3));

        return ans;
    }
    // approac 2
    int diameterOfBinaryTreeFast(TreeNode *root)
    {
        return diameterFast(root).first;
    }
};
