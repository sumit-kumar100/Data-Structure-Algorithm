/*
@ Copy List with Random Pointer
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
*/

// CODE LINK : https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    // constructor
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

// print List
void printList(Node *head)
{

    Node *iterator = head; // storing address of head
    while (iterator)
    {
        if (iterator->random)
        {
            cout << "Node : " << iterator->val << " "
                 << "Random : " << iterator->random->val << endl;
        }
        else
        {
            cout << "Node : " << iterator->val << " "
                 << "Random : " << 0 << endl;
        }
        iterator = iterator->next;
    }
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node *copyLinkedListWithRandomPointersWithMap(Node *head)
{
    // step-1 create a clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    // step-2 create a map
    unordered_map<Node *, Node *> oldToNew;
    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        cloneNode->random = oldToNew[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

Node *copyLinkedListWithRandomPointersWithoutMap(Node *head)
{
    // step 1: Create a Clone List
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    // step 2: insert nodes of Clone List in between originalList
    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step 3: Random pointer copy
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        if (originalNode->random != NULL)
        {
            cloneNode->random = originalNode->random->next;
        }
        else
        {
            cloneNode->random = originalNode->random;
        }
        // move one step
        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
        // if next is not null move one more step
        if (originalNode->next != NULL && cloneNode->next != NULL)
        {
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
    }

    // step 4: revert step 2 changes
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode && cloneNode)
    {
        originalNode->next = originalNode->next ? originalNode->next->next : originalNode->next;
        cloneNode->next = cloneNode->next ? cloneNode->next->next : cloneNode->next;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // step 5 answer return
    return cloneHead;
}

int main()
{
    // setting linked list and their random pointers
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    // WITH MAP
    // Node *copy1 = copyLinkedListWithRandomPointersWithMap(head);
    // printList(copy1);

    // WIHOUT MAP
    Node *copy2 = copyLinkedListWithRandomPointersWithoutMap(head);
    printList(copy2);
}