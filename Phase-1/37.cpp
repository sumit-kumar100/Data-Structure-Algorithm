#include <iostream>
#include <vector>
using namespace std;

long long int mySqrt(int x)
{

    int s = 0, e = x;
    long long int mid = s + (e - s) / 2;

    long long int ans = -1;
    while (s <= e)
    {
        long long int square = mid * mid; // will handle long integer overflow

        if (square == x)
        {
            return mid;
        }
        else if (square < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    cout << mySqrt(2147395599);

    return 0;
}