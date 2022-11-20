#include <iostream>
using namespace std;

// Get Sum using recursion
int getSum(int *arr, int size)
{
    // Base Case
    if (size == 0)
        return 0;

    return arr[0] + getSum(arr + 1, size - 1);
}

// Linear Search using Recursion
bool search(int *arr, int size, int key)
{
    // Base Case
    if (size == 0)
        return false;

    // Smaller Problem
    if (arr[0] == key)
        return true;

    // Bigger Problem
    int found = search(arr + 1, size - 1, key);
    return found;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << getSum(arr, 6);
    cout << endl;
    cout << search(arr, 6, 2);
    return 0;
}
