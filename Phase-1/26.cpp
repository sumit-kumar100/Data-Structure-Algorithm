#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "printing the array " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int getMin(int arr[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int getMax(int arr[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

void reverseArray1(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            arr[j] = arr[j] ^ arr[j + 1];
            arr[j + 1] = arr[j] ^ arr[j + 1];
            arr[j] = arr[j] ^ arr[j + 1];
        }
    }
}

void reverseArray2(int arr[], int size)
{
    for (int i = 0; i < (size / 2); i++)
    {
        arr[i] = arr[i] ^ arr[size - i - 1];
        arr[size - i - 1] = arr[i] ^ arr[size - i - 1];                         
        arr[i] = arr[i] ^ arr[size - i - 1];
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printArray(arr, 10);

    cout << "The mininum number is :- ";
    cout << getMin(arr, 10);

    cout << endl;

    cout << "The maximum number is :- ";
    cout << getMax(arr, 10);

    cout << endl;
    cout << "Enter the element to be searched :- ";
    int key;
    cin >> key;
    cout << "Element Present :- " << search(arr, 10, key);

    cout << endl;
    cout << "Reversing the array Approach 1";
    reverseArray2(arr, 10);
    cout << endl;
    printArray(arr, 10);
}