/*
@ Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false


Constraints:

-231 <= n <= 231 - 1
*/
#include <iostream>
#include <math.h>
using namespace std;


// LINK :- https://leetcode.com/problems/power-of-two/

bool isPowerOfTwo(int n)
{

    int exponent = 0, temp = n;

    while (temp > 1)
    {
        temp /= 2;
        exponent++;
    }

    return pow(2, exponent) == n;
}