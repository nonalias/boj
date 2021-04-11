#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int card[53];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> card[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int status = 0;
            if (card[j] < card[j + 1])
                status = 1;
            if (card[j] <= card[i])
                card[j] = 0;
            if (status)
                break;
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        //cout << card[i] << " ";
        if (card[i])
            count++;
    }
    cout << count;
}