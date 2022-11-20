// Quick Sort

#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];

    // couting number of element greater than pivot element
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wale part sambhal lete ha
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] >= pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    // Base Case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // pahele partition kar do
    int p = partition(arr, s, e);

    // left part sort kar do
    quickSort(arr, s, p - 1);

    // Right part sort kar do
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[9] = {15, 18, 24, 12, 89, 34, 99, 3, 105};

    cout << "Before Sorting" << endl;

    for (int i = 0; i <= 9; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "After Sorting" << endl;

    cout << endl;
    quickSort(arr, 0, (10 - 1));

    for (int i = 0; i <= 9; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}