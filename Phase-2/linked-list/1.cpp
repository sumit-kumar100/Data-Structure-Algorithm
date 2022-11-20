// SINGLY LINKED LIST

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
    void pushAtBegin(int new_data)
    {
        Node *temp = new Node(new_data);
        temp->next = head;
        head = temp;
    }

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

    // insert at a particular position
    void pustAtPosition(int position, int new_data)
    {
        Node *iterator = this->head;
        int count = 1;
        while (count < position - 1)
        {
            iterator = iterator->next;
            count++;
        }
        // storing current -> next before connecting it to new node
        Node *temp = iterator->next;
        Node *new_node = new Node(new_data);
        iterator->next = new_node;
        new_node->next = temp;
    }

    // insert at a particular index
    void pushAtIndex(int index, int new_data)
    {
        // if need to be inserted at 0 position
        if (index == 0)
        {
            Node *temp = this->head;
            Node *new_node = new Node(new_data);
            this->head = new_node;
            new_node->next = temp;
            return;
        }
        Node *iterator = this->head;
        int count = 0;
        while (count < (index - 1))
        {
            iterator = iterator->next;
            count++;
        }
        // storing current -> next before connecting it to new node
        Node *temp = iterator->next;
        Node *new_node = new Node(new_data);
        iterator->next = new_node;
        new_node->next = temp;
    }

    void deleteAtIndex(int index)
    {
        // if need to be deleted at 0 position
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
        Node *to_be_deleted = iterator->next;
        iterator->next = iterator->next->next;
        // now deleted from heap also
        delete to_be_deleted;
    }

    // isCircular list
    bool isCircular(Node *head)
    {
        if (head == NULL)
        {
            return true;
        }
        Node *temp = head->next;
        while (temp != NULL && temp != head)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            return true;
        }
        return false;
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
    cout << "FIRST LINKED LIST" << endl;
    LinkedList lst1;
    lst1.pushAtBegin(10);
    lst1.pushAtBegin(12);
    lst1.pushAtBegin(15);
    lst1.printList();

    cout << endl;
    bool isCircular = lst1.isCircular(lst1.head);
    cout << "IS CIRCULAR LINKED LIST : " << isCircular << endl;

    cout << "=================================================" << endl;

    cout << "SECOND LINKED LIST" << endl;
    LinkedList lst2;
    lst2.pushAtEnd(10);
    lst2.pushAtEnd(12);
    lst2.pushAtEnd(15);
    lst2.pushAtEnd(20);
    lst2.printList();

    cout << endl;

    lst2.pustAtPosition(3, 50);
    lst2.printList();

    cout << endl;

    lst2.pushAtIndex(0, 78);
    lst2.printList();

    cout << endl;

    lst2.deleteAtIndex(2);
    lst2.printList();

    return 0;
}