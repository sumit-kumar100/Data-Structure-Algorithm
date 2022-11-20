//@ Check Linked list is palindrone or not

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

    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }

    Node *reverse(Node *middle)
    {
        Node *prev = NULL;
        Node *curr = middle;

        while (curr != NULL)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr; // this statement must come before next line important that is next line very important otherwise curr will be changed that may create problem
            curr = forward;
        }

        return prev;
    }

    bool isPalindrome(Node *head)
    {
        if (head == NULL)
        {
            return true;
        }

        // step- 1 find middle
        Node *middle = getMid(head);

        // step - 2  IMPORTANT STEP DO IT SINCIERLEY
        Node *temp = middle->next;
        middle->next = reverse(temp); // middle->next apne aage reverse wali laga le jo reverse function ne diya hain.

        // step3 = Compare both values
        Node *head1 = head;
        Node *head2 = middle->next;

        bool result = true;
        while (head2 != NULL)
        {
            if (head1->data != head2->data)
            {
                result = false;
                break;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // repeat step - 2 to make linked list back to noraml
        temp = middle->next;
        middle->next = reverse(temp); // middle->next apne aage reverse wali laga le jo reverse function ne diya hain.

        return result;
    }

    // printing linked list
    void printList(Node *head)
    {
        Node *iterator = head;
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
    lst1.pushAtEnd(1);
    lst1.pushAtEnd(2);
    lst1.pushAtEnd(3);
    lst1.pushAtEnd(4);
    lst1.pushAtEnd(5);
    lst1.pushAtEnd(6);
    lst1.pushAtEnd(7);
    lst1.pushAtEnd(8);
    lst1.pushAtEnd(9);
    lst1.pushAtEnd(10);
    lst1.pushAtEnd(11);
    lst1.printList(lst1.head);
    cout << endl;
    cout << lst1.isPalindrome(lst1.head);
    cout << endl;
    lst1.printList(lst1.head);
    return 0;
}