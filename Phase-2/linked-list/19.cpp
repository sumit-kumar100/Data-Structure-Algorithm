/*
@ Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

// CODE LINK : https://leetcode.com/problems/add-two-numbers/description/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head = NULL;

    // Function to insert a new node at the beginning
    void pushAtEnd(int new_data)
    {
        Node *iterator = this->head;
        Node *temp = new Node(new_data);

        // Will handle first time
        if (iterator == NULL)
        {
            this->head = temp;
            return;
        }

        // keep increasing the iterator
        while (iterator->next)
        {
            iterator = iterator->next;
        }

        iterator->next = temp;
    }
};

// print List
void printList(Node *head)
{

    Node *iterator = head; // storing address of head
    while (iterator)
    {
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void reverse(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

Node *addTwoNumbersApproach1(Node *&l1, Node *&l2)
{
    // step-1 reverse both the linked list
    reverse(l1, l1, NULL);
    reverse(l2, l2, NULL);

    // step-2 find answer
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 0;
    Node *first = l1;
    Node *second = l2;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);

        if (first != NULL)
        {
            first = first->next;
        }

        if (second != NULL)
        {
            second = second->next;
        }

        carry = sum / 10;
    }

    // step-3 reverse linked list to make linked list normal
    reverse(l1, l1, NULL);
    reverse(l2, l2, NULL);

    // step - 4 reverse the answer
    reverse(ansHead, ansHead, NULL);
    return ansHead;
}

Node *addTwoNumbersAlternateApproach(Node *l1, Node *l2)
{

    // step-1 reverse both the linked list
    reverse(l1, l1, NULL);
    reverse(l2, l2, NULL);

    // step-2 find answer
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 0;

    while (l1 != NULL && l2 != NULL)
    {
        int sum = carry + l1->data + l2->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        int sum = carry + l1->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        int sum = carry + l2->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        l2 = l2->next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    // step-3 reverse linked list to make linked list normal
    reverse(l1, l1, NULL);
    reverse(l2, l2, NULL);

    // step - 4 reverse the answer
    reverse(ansHead, ansHead, NULL);
    return ansHead;
}

int main()
{
    LinkedList lst1;
    lst1.pushAtEnd(1);
    lst1.pushAtEnd(2);
    lst1.pushAtEnd(3);

    LinkedList lst2;
    lst2.pushAtEnd(1);
    lst2.pushAtEnd(2);
    lst2.pushAtEnd(3);

    Node *addedResult = addTwoNumbersApproach1(lst1.head, lst2.head);
    // answer without reversed just jneed to reverse
    printList(addedResult);

    cout << endl;

    Node *addedResult2 = addTwoNumbersAlternateApproach(lst1.head, lst2.head);
    // answer without reversed just jneed to reverse
    printList(addedResult2);

    return 0;
}