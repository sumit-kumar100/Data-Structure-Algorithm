// Reverse a string and check palindrome using recursion
#include <iostream>
#include <string>
using namespace std;

void reverse(string &str, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // Processing swapping
    swap(str[s], str[e]);

    // Recursive Call
    reverse(str, s + 1, e - 1);
}

bool checkPalinDrome(string &str, int s, int e)
{
    // base cases
    if (s >= e)
    {
        return true;
    }

    if (str[s] != str[e])
    {
        return false;
    }

    return checkPalinDrome(str, s + 1, e - 1);
}
int main()
{
    string s = "abcde";

    reverse(s, 0, s.size() - 1);

    string p = "NITIN";

    bool isPalin = checkPalinDrome(p, 0, p.size() - 1);

    cout << s << endl << isPalin;
}
