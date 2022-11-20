#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the number :- ";
    cin >> num;

    int money = 100;

    while (num)
    {
        switch (money)
        {
        case 100:
            if ((num / 100) >= 1)
            {
                cout << "Number of 100 rupee requiered is :- " << (num / 100) << endl;
                num = num % 100;
            }
            else
            {
                cout << "Number of 100 rupee requiered is :- " << 0 << endl;
            }
            money = 50;
            break;
        case 50:
            if ((num / 50) >= 1)
            {
                cout << "Number of 50 rupee requiered is :- " << (num / 50) << endl;
                num = num % 50;
            }
            else
            {
                cout << "Number of 50 rupee requiered is :- " << 0 << endl;
            }
            money = 20;
            break;
        case 20:
            if ((num / 20) >= 1)
            {
                cout << "Number of 20 rupee requiered is :- " << (num / 20) << endl;
                num = num % 20;
            }
            else
            {
                cout << "Number of 20 rupee requiered is :- " << 0 << endl;
            }
            money = 10;
            break;
        case 10:
            if ((num / 10) >= 1)
            {
                cout << "Number of 10 rupee requiered is :- " << (num / 10) << endl;
                num = num % 10;
            }
            else
            {
                cout << "Number of 10 rupee requiered is :- " << 0 << endl;
            }
            num = 0;
            break;
        default:
            break;
        }
    }
}