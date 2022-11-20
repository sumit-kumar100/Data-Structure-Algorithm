// Decimal to Binary

#include <iostream>
#include <math.h>
using namespace std;

int decimalToBinary(int n)
{
    int ans = 0, i = 0;
    while (n)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    return ans;
}

int main()
{
    int num;
    int result[100];

    cout << "Enter a Decimal number :- ";
    cin >> num;

    int i = 0;
    while (num)
    {
        result[i] = (num % 2);
        num = num / 2;
        i++;
    }

    int j = 0;
    while (result[j] == 1 || result[j] == 0)
    {
        cout << result[j];
        j++;
    }

    return 0;
}