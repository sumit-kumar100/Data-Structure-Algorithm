/*
1 2 3 4 5 5 4 3 2 1
1 2 3 4 * * 4 3 2 1
1 2 3 * * * * 3 2 1
1 2 * * * * * * 2 1
1 * * * * * * * * 1
* * * * * * * * * *
 */

#include <iostream>
using namespace std;

int main()
{
    int row = 5, col = 5;

    int i = 0;
    while (i <= row)
    {
        // Part One
        int j = 1;
        while (j <= (col - i))
        {
            cout << j << ' ';
            j++;
        }

        // Part Two
        int k = 0;
        while (k < (i * 2))
        {
            cout << '*' << ' ';
            k++;
        }

        // Part Three
        int l = row - i;
        while (l > 0)
        {
            cout << l << ' ';
            l--;
        }

        cout << endl;
        i++;
    }

    return 0;
}
