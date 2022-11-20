/*
@ Reverse Words in a String
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


*/

// CODE LINK :- https://leetcode.com/problems/reverse-words-in-a-string/

#include <iostream>
#include <string>
using namespace std;

void reverseStringFromK(string &st, int k)
{
    int s = k;
    int e = st.length() - 1;

    while (s <= e)
    {
        swap(st[s++], st[e--]);
    }
}

string trim(string st)
{
    int left = 0, right = st.length() - 1;
    while (st[left] == 32)
        left++;
    while (st[right] == 32)
        right--;

    string temp;
    for (int i = left; i <= right; i++)
    {
        temp.push_back(st[i]);
    }
    return temp;
}

string filterString(string st)
{
    // Triming from left and right;
    st = trim(st);

    // Removing extra spaces between words
    string temp;
    int i = 0;
    while (i < st.length())
    {
        if (st[i] == 32)
        {
            temp.push_back(st[i]);
            while (st[i] == 32)
            {
                i++;
            }
        }
        else
        {
            temp.push_back(st[i]);
            i++;
        }
    }
    return temp;
}

int main()
{

    string s = "the sky is blue";

    string temp;

    int n = s.length() - 1;

    int reversefromIndex = 0;

    for (int i = n; i >= 0; i--)
    {

        if (s[i] != 32)
        {
            temp.push_back(s[i]);
        }
        else
        {
            reverseStringFromK(temp, reversefromIndex);
            temp.push_back(s[i]);
            reversefromIndex = temp.length();
        }
    }

    // Statement to reverse the last remaining word
    reverseStringFromK(temp, reversefromIndex);

    cout << filterString(temp);

    return 0;
}