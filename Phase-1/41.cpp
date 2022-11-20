// Selection sort

#include <iostream>
#include <vector>
using namespace std;

void printNums(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// Selection Sort
void selectionSort(vector<int> nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
            {
                swap(nums[i], nums[j]);
            }
        }
    }
    printNums(nums, n);
}

// Bubble Sort
void bubbleSort(vector<int> nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    printNums(nums, n);
}

// Optimise Bubble Sort
void OptimisedbubbleSort(vector<int> nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    printNums(nums, n);
}

// Insertion Sort with for loop
void insertionSort(vector<int> nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = nums[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (nums[j] > temp)
            {
                nums[j + 1] = nums[j];
            }
        }
        nums[j + 1] = temp;
    }
    printNums(nums, n);
}

// Insertion Sort with while loop
void insertionSort2(vector<int> nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > temp)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
    printNums(nums, n);
}

int main()
{
    vector<int> num1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> num2 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> num3 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> num4 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> num5 = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    selectionSort(num1, num1.size());
    cout << endl;
    bubbleSort(num2, num2.size());
    cout << endl;
    OptimisedbubbleSort(num3, num3.size());
    cout << endl;
    insertionSort(num4, num4.size());
    cout << endl;
    insertionSort2(num5, num5.size());
    cout << endl;
}