/*
//@ 103. Binary Tree Zigzag Level Order Traversal

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

CODE LINK : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        // map to store <horizontal-distance> -> <level,[value]>
        map<int, map<int, vector<int>>> mp;
        // queue to store ( <TreeNode> , (horizontal-distance , level) )
        queue<pair<TreeNode *, pair<int, int>>> q;
        // initially pushing root to queue
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            // taking out front from queue
            pair<TreeNode *, pair<int, int>> front = q.front();
            q.pop();

            // taking out front node
            TreeNode *frontNode = front.first;
            // taking out horizonal-distance
            int hd = front.second.first;
            // taking out level
            int lvl = front.second.second;

            // pushing the answer to mp
            mp[hd][lvl].push_back(frontNode->val);

            // baki case recursion solve kar dega
            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }
            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        // Note : By default, a Map in C++ is sorted in increasing order based on its key.
        vector<vector<int>> ans;
        for (auto i : mp)
        {
            vector<int> temp;
            for (auto j : i.second)
            {
                // sorting vector
                sort(j.second.begin(), j.second.end());
                for (auto k : j.second)
                {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        // last-step return the answer
        return ans;
    }
};