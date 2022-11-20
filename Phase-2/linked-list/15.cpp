// Sort zero,one & two in linked list.

#include <iostream>
#include <map>
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

    void sortZeroOneTwo(Node *&head)
    {
        Node *temp = head;
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zeroCount++;
            }
            else if (temp->data == 1)
            {
                oneCount++;
            }
            else if (temp->data == 2)
            {
                twoCount++;
            }
            temp = temp->next;
        }

        temp = head;
        // Here we are just changing the data not the head of linked list.
        while (temp != NULL)
        {
            if (zeroCount)
            {
                temp->data = 0;
                zeroCount--;
            }
            else if (oneCount)
            {
                temp->data = 1;
                oneCount--;
            }
            else if (twoCount)
            {
                temp->data = 2;
                twoCount--;
            }
            temp = temp->next;
        }
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
    lst.pushAtEnd(0);
    lst.pushAtEnd(1);
    lst.pushAtEnd(2);
    lst.pushAtEnd(0);
    lst.pushAtEnd(1);
    lst.pushAtEnd(2);
    lst.pushAtEnd(0);
    lst.pushAtEnd(1);
    lst.pushAtEnd(2);
    lst.pushAtEnd(0);

    lst.printList();

    lst.sortZeroOneTwo(lst.head);

    cout << endl;

    // print after removing the duplicates from the linked list
    lst.printList();

    return 0;
}