/*
Check If The String Is A Palindrome
PROBLEM STATEMENT
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :

String 'S' is NOT case sensitive.
Example :

Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.
Input Format :
The very first line of input contains an integer 'T' denoting the number of test cases.

The first line of every test case contains the string 'S'.
Output Format :
For each test case, print “Yes” if 'S' is a palindrome, and “No” otherwise.

Print the output of each test case in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Follow Up :
Can you solve the problem using O(1) space complexity?
Constraints :
1 <= T <= 100
1 <= Length(S) <= 10^4

Where 'T' denotes the number of test cases and 'S' denotes the given string.

Time Limit : 1 sec

*/

// CODE LINK :- https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633

#include <iostream>
#include <string>
using namespace std;

bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}

char lowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isValidPalindrome(string s)
{
    string temp;
    // faltu hata do
    for (int j = 0; j < s.length(); j++)
    {
        if (valid(s[j]))
        {
            temp.push_back(s[j]);
        }
    }
    // Lowercase mein kar do
    for (int j = 0; j < temp.length(); j++)
    {
        temp[j] = lowerCase(temp[j]);
    }

    int start = 0, end = temp.length() - 1;

    while (start <= end)
    {
        if (temp[start++] != temp[end--])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string word = "c1    0$d@eeD01c";
    cout << isValidPalindrome(word);
    return 0;
}