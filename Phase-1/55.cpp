/*
@. Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".


Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.

*/

#include <iostream>
#include <string>
using namespace std;

// CODE LINK :- https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

// OPTIMISED SOLUTION
string removeOccurrences(string s, string part)
{
    while (s.size() != 0 && s.find(part) <= s.size())
    {
        s.erase(s.find(part), part.size());
    }
    return s;
}

// CUSTOM APPROACH NOT OPTIMISED;
int find(string s, string part)
{
    int start = 0, end = s.size() - 1;

    while (start < s.size())
    {
        // finding left most character
        while (s[start] != part[0] && start < s.size())
        {
            start++;
        }
        // finding right most character
        while (s[end] != part[part.size() - 1] && end >= 0)
        {
            end--;
        }

        if ((end - start + 1) == part.size())
        {
            bool valid = true;
            int n = 0;
            for (int i = start; i <= end; i++)
            {
                if (part[n] != s[i])
                {
                    valid = false;
                    break;
                }
                n++;
            }
            if (valid)
            {
                return start;
            }
            end--;
        }
        else if (start <= end)
        {
            end--;
        }
        else
        {
            start++;
            end = s.size() - 1;
        }
    }
    return -1;
}

void erase(string &s, int from, int to)
{
    string temp;

    for (int i = 0; i < s.size(); i++)
    {
        if ((i < from) || (i > to))
        {
            temp.push_back(s[i]);
        }
    }
    s = temp;
}

int main()
{
    string s1 = "axxxxyyyyb", part1 = "xy";
    while (s1.size() != 0 && find(s1, part1) <= s1.size())
    {
        erase(s1, find(s1, part1), (find(s1, part1) + part1.size() - 1));
    }
    cout << s1;


    string s2 = "axxxxyyyyb", part2 = "xy";
    cout << removeOccurrences(s2, part2);

    return 0;
}