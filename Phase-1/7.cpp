/*
1
2 1 
3 2 1 
4 3 2 1 
5 4 3 2 1
 */

#include <iostream>
using namespace std;

int main()
{
    int row = 5;

    int i = 1;
    while (i <= row)
    {
        int j = i;
        while (j > 0)
        {
            cout << j;
            j--;
        }
        cout << endl;
        i++;
    }
}
