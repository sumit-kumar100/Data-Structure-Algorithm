/*
@ Sort Linked List using Merge Sort
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Input: head = []
Output: []

*/

// CODE LINK : https://leetcode.com/problems/sort-list/description/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

// print List
void printNext(Node *head)
{
    Node *iterator = head;
    while (iterator)
    {
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
}

void printChild(Node *head)
{
    Node *iterator = head->child;
    while (iterator)
    {
        cout << iterator->data << " ";
        iterator = iterator->child;
    }
}

void flattenLinkedList(Node *head, Node *&ans)
{
    // base-case
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        ans->next = newNode;
        ans = newNode;
        temp = temp->child;
    }
    flattenLinkedList(head->next, ans);
}

int main()
{

    Node *head = new Node(1);
    head->child = new Node(2);
    head->child->child = new Node(3);

    head->next = new Node(4);
    head->next->child = new Node(5);
    head->next->child->child = new Node(6);

    head->next->next = new Node(7);
    head->next->next->child = new Node(8);

    head->next->next->next = new Node(9);
    head->next->next->next->child = new Node(12);

    head->next->next->next->next = new Node(20);
    Node *ans = new Node(-1);
    Node *temp = ans;
    flattenLinkedList(head, temp);

    printNext(ans->next);
}