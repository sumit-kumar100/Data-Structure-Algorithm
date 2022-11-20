/*
@ Burning Tree
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Example 1:

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value
8 is set on fire.
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    /
 8    10
Target Node = 10
Output: 5

Your Task:
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
*/

// CODE LINK : https://practice.geeksforgeeks.org/problems/burning-tree/1

#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
    {

        Node *res = NULL;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            if (front->data == target)
            {
                res = front;
            }

            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
                ;
            }

            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }
    int burnTree(Node *root, map<Node *, Node *> nodeToParent)
    {

        map<Node *, bool> visited;
        queue<Node *> q;
        q.push(root);
        visited[root] = true;

        int ans = 0;

        while (!q.empty())
        {
            bool flag = false;
            // this loop will burn adjacent nodes simultaneously
            // i.e node = 2 then , [2][1,4,5][3,8,10][7] 4second.
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();

                if (front->left && !visited[front->left])
                {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }

                if (front->right && !visited[front->right])
                {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }

                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }

            if (flag)
                ans++;
        }

        return ans;
    }
    int minTime(Node *root, int target)
    {
        // step-1 & step-2 create parent and node mapping ans also return target node.
        map<Node *, Node *> nodeToParent;
        Node *targetNode = createParentMapping(root, target, nodeToParent);
        // step-3 burn the tree;
        return burnTree(targetNode, nodeToParent);
    }
};