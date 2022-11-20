/*
@ Merge Two Sorted Lists
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/

// CODE LINK : https://leetcode.com/problems/merge-two-sorted-lists/description/

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

    Node *solve(Node *first, Node *second)
    {
        Node *head = new Node(-1);
        Node *curr = head;

        while (first != NULL && second != NULL)
        {
            if (first->data <= second->data)
            {
                curr->next = first;
                first = first->next;
            }
            else
            {
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }

        if (first != NULL)
        {
            curr->next = first;
        }

        if (second != NULL)
        {
            curr->next = second;
        }

        return head->next;
    }

    Node *solveByRecursion(Node *&head, Node *&curr, Node *&first, Node *&second)
    {
        if (first == NULL || second == NULL)
        {
            if (first != NULL)
            {
                curr->next = first;
            }

            if (second != NULL)
            {
                curr->next = second;
            }
            return head->next;
        }

        if (first->data <= second->data)
        {
            curr->next = first;
            first = first->next;
        }
        else
        {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;

        return solveByRecursion(head, curr, first, second);
    }

    Node *sort(Node *&first, Node *&second)
    {
        if (first == NULL)
        {
            return second;
        }
        if (second == NULL)
        {
            return first;
        }

        Node *result = solve(first, second);

        return result;
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
    lst.pushAtEnd(4);

    LinkedList lst2;
    lst2.pushAtEnd(1);
    lst2.pushAtEnd(3);
    lst2.pushAtEnd(4);

    cout << "Before Merge" << endl;
    lst.printList();
    cout << endl;
    lst2.printList();

    cout << endl;
    cout << "After merge" << endl;

    // lst.head = lst.solve(lst.head, lst2.head);

    Node *head = new Node(-1);
    Node *curr = head;
    lst.head = lst.solveByRecursion(head, curr, lst.head, lst2.head);

    lst.printList();

    return 0;
}