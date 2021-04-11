#include <iostream>

using namespace std;

int main(void)
{
    int N, PC;

    cin >> N >> PC;
    int L = 1;
    int R = N;
    int cur;
    while (L != R)
    {
        if (cur % 3 == 0)
            R--;
        if (cur % 3 == 1)
            L++;
        if (cur % 3 == 2)
        {
            if (R - PC > PC - L)
                R--;
            else
                L++;
        }
        cur += 1;
        cur %= 3;
    }
    if (L == PC && PC == R)
        cout << "YES";
    else
        cout << "NO";
}