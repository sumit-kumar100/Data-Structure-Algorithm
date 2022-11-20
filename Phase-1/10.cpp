/*
A
B C
D E F
G H I J
K L M N O
 */

#include <iostream>
using namespace std;

int main()
{
    int row = 5;
    char word = 65;

    int i = 1;
    while (i <= row)
    {
        int j = 1;
        while (j < i + 1)
        {
            cout << word;
            j++;
            word++;
        }
        cout << endl;
        i++;
    }
}
