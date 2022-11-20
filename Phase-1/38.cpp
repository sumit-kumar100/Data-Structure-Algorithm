/*
@ Allocate Books

Given an array ‘arr’ of integer numbers .
where ‘arr[i]’ represents the number of pages
in the ‘i-th’ book. There are  ‘m’ number of students
and the task is to allocate all the books to their students.
Allocate books in such a way that

1. Each student gets at least one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a contiguous manner.

Let’s consider ‘n=4’ (number of books ) and ‘m=2’ (number of students).
‘arr = { 10, 20, 30, 40 }’.

All possible way to allocate the ‘4’ books in ‘2’ number of students is -
*/

// CODE LINK :- https://www.codingninjas.com/codestudio/problems/allocate-books_1090540
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool isPossibleSolution(vector<int> nums, int n, int m, int mid)
{

    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        // Keep adding while this condition in true
        if (pageSum + nums[i] <= mid)
        {
            pageSum += nums[i];
        }
        else
        {
            // Reach to second student
            studentCount++;
            // if student is greater than no. of given student or nums[i] is greater than the mid
            if (studentCount > m || nums[i] > mid)
            {
                return false;
            }
            // Add current page to page sum
            pageSum = nums[i];
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {10, 20, 30, 40};
    int n = nums.size(); // No. of books
    int m = 2;           // No. of student

    // Making binary search space in this case it is 0 - 100
    int start = 0;
    int end = accumulate(nums.begin(), nums.end(), 0); // sum of nums i.e 100
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {

        if (isPossibleSolution(nums, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    cout << ans;

    return 0;
}