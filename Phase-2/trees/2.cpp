/* Level Order Traversal in Trees */
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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana wala complete ho chuka hain
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    int arr[100] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    int index = 0;

    // Build Tree
    root = buildTree(root, arr, index);

    // print tree in lever Order Traversal
    cout << endl <<  "LEVEL ORDER TRAVERSAL" << endl;
    levelOrderTraversal(root);

    // preOrder traversal
    cout << endl << "PRE-ORDER TRAVERSAL" << endl;
    preOrder(root);

    // inOrder traversal
    cout << endl << "IN-ORDER TRAVERSAL" << endl;
    inOrder(root);

    // postOrder traversal
    cout << endl <<"POST-ORDER TRAVERSAL" << endl;
    postOrder(root);
}
