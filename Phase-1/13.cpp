// Complement of a number i.e negative

#include <iostream>
using namespace std;

int main()
{
    int num;

    cout << "Enter a number :- ";
    cin >> num;

    // num 1'st complement
    num = ~num;

    // num 2'nd complement
    num = num + 1;

    cout << "Complement of Number is :- " << num;

    return 0;
}