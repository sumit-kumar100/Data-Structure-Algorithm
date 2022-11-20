/*
AP :- Take first term and difference from user ? Also take the term to find ?
*/

#include <iostream>
using namespace std;

int AP(int first_term, int difference, int nth_tern)
{
    return first_term + (nth_tern - 1) * difference;
}

int fabonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fabonacci(n - 1) + fabonacci(n - 2);
}

void fabonacci2(int n)
{
    cout << 0 << ' ' << 1 << ' ';

    int a = 0, b = 1;
    for (int i = 2; i < n; i++)
    {
        int c = a + b;
        cout << c << ' ';
        a = b;
        b = c;
    }
}

int main()
{
    // Arithmetic Progress
    int a, d, n;
    cout << "Enter the first term , differecne and the term to be find.";
    cin >> a >> d >> n;
    cout << AP(a, d, n);

    // Fabonacci Series
    int num;
    cout << "Enter the number for fabonacci series";
    cin >> num;
    cout << fabonacci(num);
    fabonacci2(num);

}