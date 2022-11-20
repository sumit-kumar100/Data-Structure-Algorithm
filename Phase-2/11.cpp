#include <iostream>
using namespace std;

// Binary Search Using Recursion
bool BinarySearch(int *arr, int s, int e, int key)
{
    // Base Cases
    if (s > e)
    {
        return false;
    }

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
    {
        return true;
    }

    // Recursive Relation
    if (key > arr[mid])
    {
        return BinarySearch(arr, mid + 1, e, key);
    }
    else
    {
        return BinarySearch(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "FOUND : " << BinarySearch(arr, 0, 9, 6);
    cout << endl;
    cout << "FOUND : " <<BinarySearch(arr, 0, 9, 789);
    return 0;
}