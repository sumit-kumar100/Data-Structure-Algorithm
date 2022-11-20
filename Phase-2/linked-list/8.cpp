/*
@Find middle of linked list
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

*/

// CODE LINK : https://leetcode.com/problems/middle-of-the-linked-list/description/

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

    int getlength()
    {
        int len = 0;
        Node *temp = this->head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        return len;
    }

    Node *findMiddle()
    {
        int len = getlength();
        int ans = (len / 2);

        Node *temp = this->head;
        int count = 0;

        while (count < ans)
        {
            temp = temp->next;
            count++;
        }
        return temp;
    }
};

int main()
{

    LinkedList lst;
    lst.pushAtEnd(10);
    lst.pushAtEnd(12);
    lst.pushAtEnd(15);
    lst.pushAtEnd(20);
    lst.pushAtEnd(50);
    lst.pushAtEnd(100);

    Node *result = lst.findMiddle();

    cout << (*result).data;
    cout << endl;
    cout << result->data;

    return 0;
}