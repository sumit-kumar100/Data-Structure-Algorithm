/*
*
* *
* * *
* * * *
* * * * *
* * * * * *
*/

#include <iostream>
using namespace std;

int main()
{
    int row = 5;

    int i = 1;
    while (i <= row)
    {
        int j = 1;
        while (j < i + 1)
        {
            cout << '*';
            j++;
        }
        cout << endl;
        i++;
    }
}
