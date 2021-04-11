#include <iostream>

using namespace std;

int main(void)
{
    int N, L, K;
    int expected = 0;

    cin >> N >> L >> K;
    int prob[101][2] = {0, };
    for (int i = 0; i < N; i++)
    {
        cin >> prob[i][0];
        cin >> prob[i][1];
    }
    for (int i = 0; i < N; i++)
    {
        if (L >= prob[i][1] && K)
        {
            K--;
            expected += 140;
            prob[i][0] = L + 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (L >= prob[i][0] && K)
        {
            K--;
            expected += 100;
            prob[i][1] = L + 1;
        }
    }
    cout << expected;
}