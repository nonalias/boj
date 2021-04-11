#include <iostream>

using namespace std;

int main(void)
{
    string str;
    char current = 'A';
    cin >> str;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int r1, r2;
        r1 = current - str[i];
        r2 = str[i] - current;
        if (r1 < 0)
            r1 += 26;
        if (r2 < 0)
            r2 += 26;
        if (r1 < r2)
            count += r1;
        else
            count += r2;
        current = str[i];
    }
    cout << count;
}