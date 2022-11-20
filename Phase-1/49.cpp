// STRING

#include <iostream>
#include <string>
using namespace std;

int strLen(string st)
{
    int count = 0;
    while (st[count] != '\0')
    {
        count++;
    }
    return count;
}

void reverseStr(string &st) // will be reflected in original stirng as we are passing the address of the string
{
    int s = 0, e = st.length() - 1;

    while (s <= e)
    {
        swap(st[s++], st[e--]);
    }
}

bool checkPalindrone(string st)
{
    int s = 0, e = st.length() - 1;

    while (s <= e)
    {
        if (st[s++] != st[e--])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string s = "HELLO WORLD";
    cout << strLen(s) << endl;
    reverseStr(s);
    cout << s << endl;

    string x = "NITIN";
    cout << checkPalindrone(x);


    return 0;
}