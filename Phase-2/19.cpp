/*
@ Letter Combinations of a Phone Number
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9']

*/

// CODE LINK : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <iostream>
#include <vector>
using namespace std;

void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
{
    // base case
    if (index >= digit.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';

    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits)
{
    vector<string> ans;

    if (digits.length() == 0)
    {
        return ans;
    }

    string output;

    int index = 0;

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, index, ans, mapping);

    return ans;
}

int main()
{
    string digits = "23";
    vector<string> result = letterCombination(digits);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}