/*
    2D Matrix
*/

#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col)
{
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // creating 2D array
    int arr[3][4];

    // Inserting the values in the matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing the array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Hard Coded array
    int arr2[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // printing the array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout << isPresent(arr2, 10, 3, 4);

    cout << isPresent(arr2, 27, 3, 4);

    return 0;
}