/*
Alternate swap in  Array
Input : {1,2,3,4,5,6}
output : {2,1,4,3,5,6}
*/

#include <iostream>
using namespace std;

// LINK :- NO LINK

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = 10;

    int pos = 0;

    for (int i = 0; i < (size / 2); i++)
    {
        // Swapping
        arr[pos] = arr[pos] ^ arr[pos + 1];
        arr[pos + 1] = arr[pos] ^ arr[pos + 1];
        arr[pos] = arr[pos] ^ arr[pos + 1];

        // Increasing Position
        pos += 2;
    }

    // Array after alternate swap
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}