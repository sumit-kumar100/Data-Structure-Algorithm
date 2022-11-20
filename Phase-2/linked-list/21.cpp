/*
@ Sort Linked List using Merge Sort
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Input: head = []
Output: []

*/

// CODE LINK : https://leetcode.com/problems/sort-list/description/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // constructor
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    ListNode *head = NULL;

    // Function to insert a new ListNode at the beginning
    void pushAtEnd(int new_data)
    {
        ListNode *iterator = this->head;
        ListNode *temp = new ListNode(new_data);

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
};

// print List
void printList(ListNode *head)
{

    ListNode *iterator = head; // storing address of head
    while (iterator)
    {
        cout << iterator->val << " ";
        iterator = iterator->next;
    }
}

ListNode *getMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge(ListNode *left, ListNode *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    ListNode *ans = new ListNode(-1);
    ListNode *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->val <= right->val)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}

ListNode *sortList(ListNode *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *mid = getMid(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    ListNode *ans = merge(left, right);

    return ans;
}

int main()
{
    LinkedList lst1;
    lst1.pushAtEnd(1);
    lst1.pushAtEnd(2);
    lst1.pushAtEnd(4);
    lst1.pushAtEnd(3);
    lst1.pushAtEnd(6);
    lst1.pushAtEnd(0);

    ListNode *sorted = sortList(lst1.head);
    printList(sorted);

    return 0;
}