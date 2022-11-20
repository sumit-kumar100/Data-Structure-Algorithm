/*
@ Print Like A Wave

For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order,
i.e., print the first column top to bottom, next column bottom to top, and so on.

For eg:-
The sine wave for the matrix:-
1 2
3 4
will be [1, 3, 4, 2].

*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;

    for (int col = 0; col < mCols; col++)
    {
        if (col & 1)
        {
            // Odd Index
            for (int row = nRows - 1; row >= 0; row--)
            {
                ans.push_back(arr[row][col]);
            }
        }
        else
        {
            // Even Index
            for (int row = 0; row < nRows; row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1, 2}, {3, 4}};

    vector<int> wave = wavePrint(nums, nums.size(), nums[0].size());

    for (int i = 0; i < wave.size(); i++)
    {
        cout << wave[i];
    }

    return 0;
}