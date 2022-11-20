/*
Inversion Count Using Merge Sort Technique
Time Complexity : O(nlogn)
Space Complexity : O(n)
*/

#include <iostream>
using namespace std;

int mergeWithInversion(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *seconnd = new int[len2];

    // Copying values
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[s + i];
    }
    for (int j = 0; j < len2; j++)
    {
        seconnd[j] = arr[mid + 1 + j];
    }

    int inversions = 0;

    // merging two sorted arrays
    int index1 = 0, index2 = 0, mainIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < seconnd[index2])
        {
            arr[mainIndex++] = first[index1++];
        }
        else
        {
            inversions += (len1 - index1);
            arr[mainIndex++] = seconnd[index2++];
        }
    }

    // If remaining element in first array
    while (index1 < len1)
    {
        arr[mainIndex++] = first[index1++];
    }
    // If remaining element in second array
    while (index2 < len2)
    {
        arr[mainIndex++] = seconnd[index2++];
    }

    // Deleing arrays from heap
    delete[] first;
    delete[] seconnd;

    return inversions;
}

int mergeWithInversionSort(int *arr, int s, int e)
{
    // Base Case
    if (s >= e)
    {
        return 0;
    }

    int mid = s + (e - s) / 2;

    return  mergeWithInversionSort(arr, s, mid) + mergeWithInversionSort(arr, mid + 1, e) + mergeWithInversion(arr, s, e);

}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << mergeWithInversionSort(arr, 0, (10 - 1));

    for (int i = 0; i <= 9; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}