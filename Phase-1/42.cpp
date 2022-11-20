// Revese an array

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;

    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
}

int main()
{
    vector<int> nums = {98, 21, 56, 22, 45, 13};

    int n = nums.size();

    for (int i = 0; i < (n / 2); i++)
    {
        swap(nums[i], nums[n - 1 - i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    

    return 0;
}