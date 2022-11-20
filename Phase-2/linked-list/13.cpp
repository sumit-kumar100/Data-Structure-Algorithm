/*
@ Remove duplicates from unsorted linked list using two loops
Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/

// CODE LINK : https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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

    Node *uniqueSortedList(Node *&head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        Node *curr = head;

        while (curr != NULL && curr->next != NULL)
        {
            Node *temp = curr;
            while (temp->next != NULL)
            {
                if (curr->data == temp->next->data)
                {
                    Node *next = temp->next->next;
                    Node *nodeToBeDeleted = temp->next;
                    delete (nodeToBeDeleted);
                    temp->next = next;
                }
                else
                {
                    temp = temp->next;
                }
            }
            curr = curr->next;
        }

        return head;
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
};

int main()
{

    // linked list
    cout << "LINKED LIST" << endl;
    LinkedList lst;
    lst.pushAtEnd(1);
    lst.pushAtEnd(2);
    lst.pushAtEnd(2);
    lst.pushAtEnd(3);
    lst.pushAtEnd(4);
    lst.pushAtEnd(3);
    lst.pushAtEnd(4);
    lst.pushAtEnd(4);
    lst.pushAtEnd(4);
    lst.pushAtEnd(5);

    lst.printList();

    // remove duplicated from sorted linked list
    lst.uniqueSortedList(lst.head);

    cout << endl;

    // print after removing the duplicates from the linked list
    lst.printList();

    return 0;
}