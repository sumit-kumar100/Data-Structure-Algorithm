// Large number factorial 

#include <iostream>
#define ull long long int
#define mod 1000000007
using namespace std;

ull fact(int n)
{
    ull ans;
    ans = 1;
    for (int i = 2; i <= n; i++)
        ans = (ans * i) % mod;
    return ans;
}
int main()
{
    fact(5000);
    return 0;
}