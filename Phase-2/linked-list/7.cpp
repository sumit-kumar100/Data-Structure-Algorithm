// Reverse Doubly Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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
        temp->prev = iterator;
        iterator->next = temp;
    }

    int getlength()
    {
        int len = 0;
        Node *temp = this->head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        return (len - 1);
    }

    // printing linked list
    void printList()
    {
        Node *iterator = this->head; // storing address of head
        int cnt = 0;
        while (iterator)
        {
            if (cnt == 0)
            {
                cout << 0 << " " << iterator->data << " " << iterator->next->data << endl;
                cnt++;
            }
            else
            {
                cout << iterator->prev->data << " " << iterator->data << " " << iterator->next->data << endl;
                cnt++;
            }
            if (cnt == getlength())
            {
                break;
            }
            iterator = iterator->next;
        }
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
        curr->prev = curr->next; // this statement must come before curr->next important that is next line very important otherwise curr->next will be changed that may create problem
        curr->next = prev;
    }
};

int main()
{
    LinkedList lst;
    lst.pushAtEnd(10);
    lst.pushAtEnd(20);
    lst.pushAtEnd(30);
    lst.pushAtEnd(40);

    lst.printList();

    cout << endl;

    lst.reverse(lst.head, lst.head, NULL);

    cout << endl;

    lst.printList();
}