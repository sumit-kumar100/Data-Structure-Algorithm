// nCr of a given number i.e nCr = n!/(r!*(n-r)!)
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return n;
    }
    return n * factorial(n - 1);
}

int nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n, r;
    cout << "Enter the value of n :- ";
    cin >> n;
    cout << "Enter the value of r :- ";
    cin >> r;
    cout << nCr(n, r);
}