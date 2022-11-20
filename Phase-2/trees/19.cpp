/*
@ Kth Ancestor in a Tree

Input:
     K = 2
     Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.


Example 2:

Input:
k=1
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

// CODE LINK : https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/0

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *solve(Node *root, int &k, int node)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    return ans->data;
}

void solve2(Node *root, int k, int node, int &ans, vector<int> &storePath)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // add current data to ancestor
    storePath.push_back(root->data);

    if (root->data == node)
    {
        // making anser from the storePath Right->left k time
        int cnt = 0;
        for (int i = storePath.size() - 1; i >= 0; i--)
        {
            if (cnt == k)
            {
                ans = storePath[i];
            }
            cnt++;
        }
        return;
    }

    // left and right recursive calls
    solve2(root->left, k, node, ans, storePath);
    solve2(root->right, k, node, ans, storePath);

    // delete current data from answer i.e, backtracking
    storePath.pop_back();
}
int kthAncestor2(Node *root, int k, int node)
{
    int ans = -1;
    vector<int> storePath;
    solve2(root, k, node, ans, storePath);
    return ans;
}