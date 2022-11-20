/*
A B C D E
A B C D E
A B C D E
A B C D E
A B C D E
 */

#include <iostream>
using namespace std;

int main()
{
    int row = 5, col = 5;

    int i = 1;
    while (i <= row)
    {
        int j = 1;
        char word = 65;
        while (j <= col)
        {
            cout << word;
            j++;
            word++;
        }
        cout << endl;
        i++;
    }
}
