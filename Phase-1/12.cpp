// Reverse an Integer

// LINK :- https://leetcode.com/problems/reverse-integer/

#include <iostream>
using namespace std;

int main()
{
    int num, reverse = 0;

    cout << "Enter a number :- ";
    cin >> num;

    while (num > 0)
    {
        int temp = num % 10;
        reverse = reverse * 10 + temp;
        num = num / 10;
    }

    cout << "Reverse of Number is :- " << reverse;

    return 0;
}