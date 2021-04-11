#include <iostream>

using namespace std;

int bills[6] = {500, 100, 50, 10, 5, 1};

int main(void)
{
    int count;
    int N;
    int i = 0;

    cin >> N;
    count = 0;
    N = 1000 - N;
    while (N)
    {
        if (N / bills[i] > 0)
        {
            count += (N / bills[i]);
            N = N % bills[i];
        }
        else
            i++;
    }
    cout << count;
}