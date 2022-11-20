/*
@ Construct Binary Tree from Preorder and Inorder Traversal
Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

*/

// CODE LINK : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
public:
    int findPosition(vector<int> inorder, int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (inorder[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int> inorder, vector<int> postorder, int &index, int inOrderStart, int inOrderEnd, int n)
    {

        // base-case
        if (index < 0 || inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        int element = postorder[index--];
        TreeNode *root = new TreeNode(element);
        // we are finding position every time instead we can get a map which stores <element : positionIndex> in parameter of inorder.
        // Map will increase space complexity of O(n) but will decrease time complexity.
        int position = findPosition(inorder, element, n);

        // recursive calls
        root->right = solve(inorder, postorder, index, position + 1, inOrderEnd, n);
        root->left = solve(inorder, postorder, index, inOrderStart, position - 1, n);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size();
        int postOrderIndex = n - 1;
        TreeNode *ans = solve(inorder, postorder, postOrderIndex, 0, n - 1, n);
        return ans;
    }
};