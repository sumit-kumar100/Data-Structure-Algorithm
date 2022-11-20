/*
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
*/

#include <iostream>
using namespace std;

int main()
{
    int row = 4, col = 4;

    int i = 1;
    while (i <= row)
    {
        int j = 1;
        while (j <= col)
        {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
}
