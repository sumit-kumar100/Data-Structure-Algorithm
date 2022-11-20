// Binary to Decimal

#include <iostream>
using namespace std;

// Power to x to n.
int power(int x, int n)
{
    int temp = x;
    while (n)
    {
        temp *= temp;
        n--;
    }
    return temp;
}

// Power to 2 to n.
// LINK :- https://leetcode.com/problems/power-of-two/
int powerofTwo(int n)
{
    int power = 1;
    while (n)
    {
        power <<= 1; // multiplying power by two each time
        n--;
    }
    return power;
}

int main()
{
    int num, result = 0;

    cout << "Enter a binary number :- ";
    cin >> num;

    int i = 0;
    while (num)
    {
        if (num % 10 == 1)
        {
            result += powerofTwo(i);
        }
        num = num / 10;
        i++;
    }

    cout << result;

    return 0;
}