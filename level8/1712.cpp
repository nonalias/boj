#include <iostream>

using namespace std;

int solution(long A, long B, long C)
{
    int     sellCount;

    if (B >= C)
        return (-1);
    sellCount = A / (C - B);
    sellCount++;
    return (sellCount);
}

int main(void)
{
    long A, B, C;

    cin >> A >> B >> C;
    cout << solution(A, B, C);
    return (0);
}