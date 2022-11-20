/* 
@ Reverse the linked list in K groups
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/

// CODE LINK : https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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

    Node *kReverse(Node *head, int k)
    {
        // base call
        if (head == NULL)
        {
            return NULL;
        }

        // step1: reverse first k nodes
        Node *next = NULL;
        Node *curr = head;
        Node *prev = NULL;
        int count = 0;

        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // step2: Recursion dekhlega aage ka
        if (next != NULL)
        {
            head->next = kReverse(next, k);
        }

        // step3: return head of reversed list
        return prev;
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
    LinkedList lst1;
    lst1.pushAtBegin(9);
    lst1.pushAtBegin(8);
    lst1.pushAtBegin(7);
    lst1.pushAtBegin(6);
    lst1.pushAtBegin(5);
    lst1.pushAtBegin(4);
    lst1.pushAtBegin(3);
    lst1.pushAtBegin(2);
    lst1.pushAtBegin(1);

    lst1.printList();

    lst1.head = lst1.kReverse(lst1.head, 2);

    cout << endl;

    lst1.printList();

    return 0;
}