// Check a number is positive or not.

#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Enter a number :- ";
    cin >> a;

    if (a > 0)
    {
        cout << "A is Positive number";
    }
    else
    {
        cout << "A is negative number";
    }
    return 0;
}