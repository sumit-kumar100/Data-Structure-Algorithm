// Sum of even number between 0 to N.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number N :- ";

    cin >> n;

    int sum = 0;
    int i = 0;

    while (i <= n)
    {
        if (!(i & 1))
        {
            sum += i;
        }
        i++;
    }

    cout << "The sum of even number to N is :- " << sum;
}