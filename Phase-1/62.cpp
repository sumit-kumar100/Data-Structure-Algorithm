/*
@ Search a 2D Matrix
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

*/

// CODE LINK : https://leetcode.com/problems/search-a-2d-matrix/description/
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int row = matrix.size(), col = matrix[0].size();

    int start = 0, end = row * col - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (target == matrix[mid / col][mid % col])
        {
            return true;
        }
        else if (target < matrix[mid / col][mid % col])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;

    cout << searchMatrix(matrix, target);
    
    return 0;
}