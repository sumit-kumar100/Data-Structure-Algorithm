#include <iostream>
using namespace std;

// here argument is copying the array it's not the actual array . Hence called call by value not call be referecne
void printArray(int arr[], int size)
{
    cout << "printing the array " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void updateArray(int arr[], int size)
{
    cout << "updating the array " << endl;

    arr[0] = 120;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    // initializing all locations with 0
    int arr1[10] = {0};
    printArray(arr1, 10);

    // initializing all locations with 0 except first place.
    int arr2[10] = {1};
    printArray(arr2, 10);

    // calculating the size of array then passing to functions.
    // size of array will be 10*4 and size of int is 4 . finally size of array is (10*4)/4.
    int arr3[10] = {0};
    printArray(arr3, (sizeof(arr3) / sizeof(int)));

    int arr4[10] = {2, 7};
    // In the above array the size of array will be 10.
    // But there is only two element . But at any cost
    // we won't be able to find the size i.e, no. of element in the array in this case that is 2.
    // Therefore we have to take that manually during run time.
    // We can also use techniques like dynamic memory allocation.

    int update[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // before update
    for (int i = 0; i < 10; i++)
    {
        cout << update[i] << ' ';
    }
    cout << endl;
    // updated
    updateArray(update, 10);
    cout << endl;
    // after update
    for (int i = 0; i < 10; i++)
    {
        cout << update[i] << ' ';
    }
    cout << endl;

    return 0;
}