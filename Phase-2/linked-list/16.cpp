// Sort zero,one & two in linked list without data replacement.

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

    void insertAtTail(Node *&tail, Node *curr)
    {
        tail->next = curr;
        tail = curr;
    }

    void sortZeroOneTwo(Node *&head)
    {
        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;
        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;
        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;

        Node *curr = head;

        // create separate list 0s, 1s and 2s
        while (curr != NULL)
        {

            int value = curr->data;

            if (value == 0)
            {
                insertAtTail(zeroTail, curr);
            }
            else if (value == 1)
            {
                insertAtTail(oneTail, curr);
            }
            else if (value == 2)
            {
                insertAtTail(twoTail, curr);
            }
            curr = curr->next;
        }

        // merge 3 sublist

        // 1s list not empty
        if (oneHead->next != NULL)
        {
            zeroTail->next = oneHead->next;
        }
        else
        {
            // 1s list -> empty
            zeroTail->next = twoHead->next;
        }

        oneTail->next = twoHead->next;
        twoTail->next = NULL;

        // setup head
        head = zeroHead->next;

        // delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
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