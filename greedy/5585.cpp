#include <iostream>

using namespace std;

int main(void)
{
    int count = 0;

    int money;

    cin >> money;
    money = 1000 - money;
    if (money / 500 > 0)
    {
        count += money / 500;
        money = money % 500;
    }
    if (money / 100 > 0)
    {
        count += money / 100;
        money = money % 100;
    }
    if (money / 50 > 0)
    {
        count += money / 50;
        money = money % 50;
    }
    if (money / 10 > 0)
    {
        count += money / 10;
        money = money % 10;
    }
    if (money / 5 > 0)
    {
        count += money / 5;
        money = money % 5;
    }
    count += money;
    cout << count;
}