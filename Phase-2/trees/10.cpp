/*
@ Boundary Traversal of binary tree
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:
Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

Example 1:
Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
      / \
     8   9

Output: 1 2 4 8 9 6 7 3

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8

As you can see we have not taken the right subtree.

CODE LINK : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
private:
    void leftBoundary(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->left != NULL || root->right != NULL)
        {
            ans.push_back(root->data);
        }

        (root->left != NULL) ? leftBoundary(root->left, ans) : leftBoundary(root->right, ans);
    }

    void leafNodes(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
    }

    void rightBoundary(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        (root->right != NULL) ? rightBoundary(root->right, ans) : rightBoundary(root->left, ans);

        if (root->left != NULL || root->right != NULL)
        {
            ans.push_back(root->data);
        }
    }

public:
    vector<int> boundary(Node *root)
    {

        vector<int> ans;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return ans;
        }

        // top boundary
        ans.push_back(root->data);
        // left boundary
        leftBoundary(root->left, ans);
        // bottom boundary
        leafNodes(root, ans);
        // right boundary
        rightBoundary(root->right, ans);

        return ans;
    }
};