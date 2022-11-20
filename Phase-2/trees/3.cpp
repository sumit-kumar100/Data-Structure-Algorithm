/*@ Count number of nodes in a tree */

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root, int arr[], int &index)
{

    root = new Node(arr[index]);

    if (arr[index] == -1)
    {
        return NULL;
    }
    index++;
    root->left = buildTree(root->left, arr, index);
    index++;
    root->right = buildTree(root->right, arr, index);

    return root;
}

void countNodes(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    countNodes(root->left, count);
    count++;
    countNodes(root->right, count);
}

void countLeafNodes(Node *root, int &leafCount)
{
    if (root == NULL)
    {
        return;
    }
    countLeafNodes(root->left, leafCount);
    if (root->left == NULL && root->right == NULL)
    {
        leafCount++;
    }
    countLeafNodes(root->right, leafCount);
}

int main()
{
    Node *root = NULL;
    int arr[100] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    int index = 0;

    // Build Tree
    root = buildTree(root, arr, index);

    // count Nodes
    int count = 0;
    countNodes(root, count);
    cout << "NUMBER OF NODES IN TREE : " << count << endl;

    // count LeafNodes
    int leftCount = 0;
    countLeafNodes(root, leftCount);
    cout << "NUMBER OF LEAF NODES IN TREE : " << leftCount << endl;
}
