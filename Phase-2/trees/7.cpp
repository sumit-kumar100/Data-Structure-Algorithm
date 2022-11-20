/*
//@ Same-Idetical Tree

Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false

CODE LINK : https://leetcode.com/problems/same-tree/description/

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
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // base-case
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        {
            return false;
        }

        // processing
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool result = p->val == q->val;

        // return answer
        return (left && right && result) ? true : false;
    }
};