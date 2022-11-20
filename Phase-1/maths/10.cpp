/*
@ Factorial Trailing Zeroes

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0

*/

// CODE LINK : https://leetcode.com/problems/factorial-trailing-zeroes/

#include<iostream>
using namespace std;


int trailingZeroes(int n)
{
    int result = 0;
    int gap = 5;

    while (gap <= n)
    {
        result += (n / gap);
        gap *= 5;
    }

    return result;
}