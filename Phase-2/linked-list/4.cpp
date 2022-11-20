// Reverse a linked List

// CODE LINK : https://leetcode.com/problems/reverse-linked-list/description/

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

    // printing linked list
    void printList()
    {
        Node *iterator = this->head; // storing address of head
        while (iterator)
        {
            cout << iterator->data << " ";
            iterator = iterator->next;
        }
    }

    void reverse()
    {
        Node *prev = NULL;
        Node *curr = this->head;

        while (curr != NULL)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr; // this statement must come before next line important that is next line very important otherwise curr will be changed that may create problem
            curr = forward;
        }

        this->head = prev;
    }

};

int main()
{

    LinkedList lst;
    lst.pushAtEnd(10);
    lst.pushAtEnd(12);
    lst.pushAtEnd(15);
    lst.pushAtEnd(20);
    // lst.printList();

    lst.reverse();

    lst.printList();

    return 0;
}