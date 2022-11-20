/*
Subsequences of String

You are given a string 'STR' containing lowercase English letters from a to z inclusive.
Your task is to find all non-empty possible subsequences of 'STR'.

example :
Input : "abc"
Output subsequences : "" "a" "b" "c" "ab" "ac" "bc" "abc" total = 8

*/

// CODE LINK : https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve(string s, int index, string output, vector<string> &ans)
{
    // Base case
    if (index >= s.size())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // Recursion tu exclude part sambhal le
    solve(s, index + 1, output, ans);

    // Recursion ab tu include part sambhal le
    char element = s[index];
    output.push_back(element);
    solve(s, index + 1, output, ans);
}

vector<string> subsets(string &s)
{

    vector<string> ans;
    string output = "";
    int index = 0;

    // Kar de bhai solve
    solve(s, index, output, ans);

    return ans;
}

int main()
{
    string s = "abc";
    vector<string> result = subsets(s);
    cout << result.size();
    return 0;
}