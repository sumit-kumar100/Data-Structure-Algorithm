// CIRCULAR LINKED LIST

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
    }
};

void insertNode(Node *&head, int element, int data)
{
    // if list is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        Node *curr = head;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next; // joining last null to first Node that is part of the circular list
        curr->next = temp;
    }
}

void deleteNode(Node *&head, int value)
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        // non empty value
        Node *prev = head;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (head == curr)
        {
            head = prev;
        }
        curr->next = NULL;
        delete curr;
    }
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

void print(Node *head)
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << head->data << " ";
        head = head->next;
    } while (head != temp);
}

int main()
{
    Node *head = NULL;
    insertNode(head, 5, 3);
    insertNode(head, 3, 5);
    insertNode(head, 5, 7);
    insertNode(head, 7, 9);
    insertNode(head, 9, 10);

    cout << "CURCULAR LINKED LIST" << endl;
    print(head);
    cout << endl;
    deleteNode(head, 5);
    cout << "DELETING A NODE FROM CIRCULAR LINKED LIST" << endl;
    print(head);
    cout << endl;
    bool result = isCircular(head);
    cout << "IS CIRCULAR LINKED LIST : " << result << endl;

    return 0;
}