/*
@ Count Primes

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0

*/

// CODE LINK : https://leetcode.com/problems/count-primes/
#include<iostream>
#include<vector>
using namespace std;

int countPrimes(int n)
{
    int cnt = 0;
    vector<bool> prime(n + 1, true); // atlease 1 size is required therefore n+1

    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (int j = 2 * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    return cnt;
}
