/*
@ Lowest Common Ancestor of a Binary Tree

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

*/

// CODE LINK : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // base cases
        if (root == NULL)
        {
            return NULL;
        }

        if (root == p || root == q)
        {
            return root;
        }

        // recursive calls
        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        // cases for LCA
        if (leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else
        {
            return NULL;
        }
    }
};