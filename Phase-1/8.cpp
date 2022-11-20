/*
A A A A A
B B B B B
C C C C C
D D D D D
E E E E E
 */

#include <iostream>
using namespace std;

int main()
{
    int row = 5, col = 5;
    char word = 65;

    int i = 1;
    while (i <= row)
    {
        int j = 1;
        while (j <= col)
        {
            cout << word;
            j++;
        }
        cout << endl;
        i++;
        word++;
    }
}
