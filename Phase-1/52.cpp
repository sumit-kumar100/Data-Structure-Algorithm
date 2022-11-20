/*
Count Maximum frequency in an word
Input : test
output : t

Input : aaasumit
output : a

Note : given word contains alpaabets only.

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string st = "output";
    int arr[26] = {0};

    for (int i = 0; i < st.length(); i++)
    {
        int number;
        char ch = st[i];

        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else
        {
            number = ch - 'A';
        }
        arr[number]++;
    }

    int max = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < arr[i])
        {
            ans = i;
            max = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    cout << finalAns;

    return 0;
}