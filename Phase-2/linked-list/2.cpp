// DOUBLY LINKED LIST

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
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

    // Push At the Beginning
    void pushAtBegin(int data)
    {
        // handling if this is first node
        if (this->head == NULL)
        {
            this->head = new Node(data);
            return;
        }
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    // Push At the End
    void pushAtEnd(int data)
    {
        // handling if this is first node
        if (this->head == NULL)
        {
            this->head = new Node(data);
            return;
        }
        Node *iterator = this->head;
        while (iterator->next)
        {
            iterator = iterator->next;
        }
        Node *temp = new Node(data);
        temp->prev = iterator;
        iterator->next = temp;
    }

    // Insert at middle
    void pustAtMiddle(int index, int data)
    {
        // handling if this is first node
        if (this->head == NULL)
        {
            this->head = new Node(data);
            return;
        }
        // handing 0 Index seperately
        if (index == 0)
        {
            Node *temp = new Node(data);
            temp->next = this->head;
            head = temp;
            return;
        }
        int count = 0;
        Node *iterator = this->head;
        while (count < index - 1)
        {
            iterator = iterator->next;
            count++;
        }
        Node *temp = new Node(data);
        temp->prev = iterator;
        temp->next = iterator->next;
        iterator->next = temp;
    }

    void deleteAtIndex(int index)
    {
        // handing 0 Index seperately
        if (index == 0)
        {
            Node *zerothNode = this->head;
            this->head = this->head->next;
            delete zerothNode;
            return;
        }

        Node *iterator = this->head;
        int count = 0;
        while (count < (index - 1))
        {
            iterator = iterator->next;
            count++;
        }
        // but deleted node is not deleted from the heap
        Node *nodeToBeDeleted = iterator->next;
        iterator->next = iterator->next->next;
        // now deleted from heap also
        delete nodeToBeDeleted;
    }

    // print List
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
    // PUSHING AT BEGGINNING
    LinkedList lst1;
    lst1.pushAtBegin(10);
    lst1.pushAtBegin(20);
    lst1.pushAtBegin(30);
    lst1.pushAtBegin(40);
    lst1.printList();

    cout << endl;

    // PUSSING AT END
    LinkedList lst2;
    lst2.pushAtEnd(10);
    lst2.pushAtEnd(20);
    lst2.pushAtEnd(30);
    lst2.pushAtEnd(40);
    lst2.printList();

    cout << endl;

    lst2.pustAtMiddle(0, 100);
    lst2.printList();

    cout << endl;

    lst2.deleteAtIndex(0);
    lst2.printList();

    cout << endl;

    lst2.deleteAtIndex(1);
    lst2.printList();

    return 0;
}