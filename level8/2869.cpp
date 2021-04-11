#include <iostream>

using namespace std;

int     solution(int A, int B, int V)
{
    int one_day_climb;

    one_day_climb = A - B;
    V -= B;
    if (one_day_climb <= 0)
        return (-1);
    if (V % one_day_climb == 0)
        return (V / one_day_climb);
    else
        return ((V / one_day_climb) + 1);
}


int main(void)
{
    int A, B, V;

    cin >> A >> B >> V;
    cout << solution(A, B, V);
}