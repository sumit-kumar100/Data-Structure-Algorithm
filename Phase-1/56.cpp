/*
@ Remove All Adjacent Duplicates In String
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

*/

#include <iostream>
#include <string>
using namespace std;

// CODE LINK : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// OPTIMISED STACK BASED SOLUTION
string removeDuplicates(string s)
{

    string temp;

    for (auto ch : s)
    {
        if (!temp.empty() && temp.back() == ch)
        {
            temp.pop_back();
        }
        else
        {
            temp.push_back(ch);
        }
    }

    return temp;
}

// CUSTOM SOLUTION NOT OPTIMESED TLE ERROR WILL GONNA OCCUR
string removeDuplicates2(string s)
{

    int start = 0, end = s.size() - 1;

    while (start < end && s.size() != 0)
    {
        int count = 1;
        while (s[start] == s[start + count])
        {
            count++;
        }
        if (count > 1)
        {
            s.erase(start, count);
            start = 0;
        }
        else
        {
            start++;
        }
    }
    return s;
}
int main()
{
    cout << removeDuplicates("abbaca");
    cout << endl;
    cout << removeDuplicates("azxxzy");
    cout << endl;
    cout << removeDuplicates2("abbaca");
    cout << endl;
    cout << removeDuplicates2("aaaaaaa");
    cout << endl;
    cout << removeDuplicates2("azxxzy");
    return 0;
}