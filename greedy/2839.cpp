#include <iostream>

using namespace std;

/*
int calc_5_and_3(int N)
{
    int count = 0;
    if (N / 5 > 0)
    {
        count += N / 5;
        N %= 5;
    }
    if (N / 3 > 0)
    {
        count += N / 3;
        N %= 3;
    }
    if (N == 0)
        return (count);
    else
        return (5000);
}

int calc_only_3(int N)
{
    int count = 0;
    if (N % 3 == 0)
        return N / 3;
    else
        return 5000;
}
*/

int main(void)
{
    int N;
    int count; 

    cin >> N;

    count = 5000;
    for (int i = 0 ; i <= N / 5; i++)
    {
        for (int j = 0; j <= N / 3; j++)
        {
            int temp = 5001;
            if (N - (i * 5 + j * 3) == 0)
                temp = i + j;
            if (count > temp)
                count = temp;
        }
    }
    if (count == 5000)
        cout << -1;
    else
    {
        cout << count;
    }
    
    /*
    count = min(calc_5_and_3(N), calc_only_3(N));
    if (count == 5000)
    {
        cout << -1;
    }
    else 
        cout << count;
    if (N != 0)
        cout << -1;
    else
        cout << count;
        */
    
}