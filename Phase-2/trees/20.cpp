/*
@ Maximum sum of Non-adjacent nodes

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and returns the maximum sum as described.

Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000
*/

// CODE LINK : https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/0

#include <iostream>
using namespace std;

struct Node
{
    int data; 
    Node *left;
    Node *right;
};

class Solution
{
private:
    pair<int, int> solve(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> res;
        res.first = root->data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);

        return res;
    }

public:
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};