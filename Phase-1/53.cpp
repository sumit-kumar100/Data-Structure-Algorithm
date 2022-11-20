// Replace spaces with @40

#include <iostream>
#include <string>
using namespace std;

void replaceSpaceWithoutExtraSpace(string &s)
{
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == ' ')
        {
            int previousLength = s.length() - 1;

            // We have one space and we need to create two extra spaces at end.
            for (int j = 0; j < 2; j++)
            {
                s.push_back('#');
            }

            int currentLength = s.length() - 1;
            while (previousLength > i)
            {
                s[currentLength--] = s[previousLength--];
            }
            s[i] = '@';
            s[i + 1] = '4';
            s[i + 2] = '0';
            i += 3;
        }
        else
        {
            i++;
        }
    }
}

void replaceSpaceWithExtraSpcae(string &s)
{
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    s = temp;
}

int main()
{
    string s = "This is me sumit";

    replaceSpaceWithExtraSpcae(s);
    replaceSpaceWithoutExtraSpace(s);

    cout << s;
    return 0;
}