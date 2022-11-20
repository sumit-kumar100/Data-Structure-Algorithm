#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter the value of a :- ";
    cin >> a;

    cout << "Enter the value of b :- ";
    cin >> b;

    char op;
    cout << "Enter the operator :- ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << (a + b);
        break;
    case '-':
        cout << (a - b);
        break;
    case '*':
        cout << (a * b);
        break;
    case '/':
        cout << (a / b);
        break;
    default:
        cout << "Please enter a valid opertor.";
        break;
    }
}