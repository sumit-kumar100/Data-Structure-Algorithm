/*
Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2)
{

    // Base case
    if (s2.size() < s1.size())
    {
        return false;
    }

    // character frequency array of s1
    int freq1[26] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        int index = s1[i] - 'a';
        freq1[index]++;
    }

    // character frequency array of s2
    int freq2[26] = {0};
    int i = 0, j = 0;

    while (j < s2.size())
    {

        int index = s2[j] - 'a';
        freq2[index]++;

        // checking if window size is valid
        if ((j - i + 1) == s1.size())
        {
            // checking if frequencies of freq1 and freq2 is same
            bool valid = true;
            for (int i = 0; i < 26; i++)
            {
                if (freq1[i] != freq2[i])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                return valid;
            }
        }

        // if window size is smaller s1 size
        if ((j - i + 1) < s1.size())
        {
            j++;
        }
        else
        {
            // Removing previous frequency
            int index = s2[i] - 'a';
            freq2[index]--;
            // moving window
            i++;
            j++;
        }
    }

    return false;
}

int main()
{
    string s1 = "ab", s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
    return 0;
}