#include <iostream>
using namespace std;

// BuBBLE SORT
void bubbleSort(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    for (int i = 0; i < (size - 1); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, size - 1);
}

// Selection Sort
void SelectionSort(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    for (int i = 1; i < size; i++)
    {
        if (arr[0] > arr[i])
        {
            swap(arr[0], arr[i]);
        }
    }

    SelectionSort(arr + 1, size - 1);
}

// Insertion Sort
void insertionSort(int *arr, int size, int n = 1)
{
    if (n == size)
    {
        return;
    }

    int temp = arr[n];
    int j = n - 1;
    while (j >= 0 && arr[j] > temp)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp;

    insertionSort(arr, size, n + 1);
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    insertionSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}