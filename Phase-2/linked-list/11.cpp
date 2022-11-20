/*
Floyd’s Cycle-Finding Algorithm:  ❤️❤️❤️❤️❤️❤️
'''
    This is the fastest method and has been described below:
    Traverse linked list using two pointers.
    Move one pointer(slow_p) by one and another pointer(fast_p) by two.
    If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
'''
*/

// Remove Cycle from Linked List If Present
// Removing Cycle by finding the beginning/start of node loop in linked list
// For above need to find the has life cycle / loop in linked list using floyd's detection cycle or you can use map apprach.

// SINGLY LINKED LIST

// CODE LINK : https://leetcode.com/problems/linked-list-cycle-ii/description/
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

    Node *floydDetectLoop(Node *&head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *slow = head;
        Node *fast = head;

        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            if (slow == fast)
            {
                return slow; // life cycle is present in the linked list
            }
        }
        return NULL;
    }

    Node *getStartingNode(Node *&head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        // performing step 1 i.e point of intersection
        Node *intersection = floydDetectLoop(head);
        if (intersection == NULL)
        {
            return NULL;
        }
        Node *slow = head;
        // performing step 2 i.e, moving forward slow and fast with one step
        while (slow != intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }

    Node *removeLoop(Node *&head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *startOfLoop = getStartingNode(head);

        if (startOfLoop == NULL)
        {
            return head;
        }

        Node *temp = startOfLoop;
        while (temp->next != startOfLoop)
        {
            temp = temp->next;
        }
        temp->next = NULL;
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
    lst.pushAtEnd(10);
    lst.pushAtEnd(12);
    lst.pushAtEnd(15);
    lst.pushAtEnd(20);

    // linked list before life cycle
    lst.printList();
    cout << endl;

    // making a loop cycle in linked list
    Node *temp = lst.head;
    lst.head->next->next->next->next = temp->next;

    // removing the lifecycle from the linked list
    lst.removeLoop(lst.head);

    // finally printing the linked list
    lst.printList();

    return 0;
}