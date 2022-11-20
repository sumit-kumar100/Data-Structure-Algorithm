// Prime Number or Not

#include <iostream>
using namespace std;

int main()
{
    int i = 2, n;

    cout << "Enter a number N :- ";
    cin >> n;

    bool flag = true;

    if (n > 1)
    {
        while (i < n)
        {
            if (n % i == 0)
            {
                flag = false;
                break;
            }
            i++;
        }
    }

    flag ? cout << "Number is Prime." : cout << "Number is not Prime.";

    return 0;
}