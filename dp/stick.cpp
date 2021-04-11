#include <iostream>
#include <vector>

using namespace std;

// 막대기를 잘랐을 때 가능한 가장 큰 가격을 알아내기
// 막대기 길이 별로 가격은 다음과 같다.
// 길이 : 0 1 2 3 4  5  6  7  8  9 10
// 가격 : 0 1 5 8 9 10 17 17 20 24 30
// 이 때 막대기 4를 잘랐을 때 가능한 가장 큰 가격은 2(5) + 2(5) = 10이 된다.

int     solution(int *price, int nbr)
{
    /*
    최댓값을 Rn 이라고 했을 때,
    R6 은 max(P6 + R0, P5 + R1, P4 + R2 ... , P0 + R6) 이다.
    따라서 반복문을 돌면서 상향식 계산법을 사용하여 해결해본다.
    */
    int r[99] = { 0, };
    for (int i = 0; i <= nbr; i++)
    {
        int q = -1;
        for (int j = i; j >= 0;  j--)
        {
            if (q < price[j] + r[i - j])
                q = price[j] + r[i - j];
        }
        r[i] = q;
    }
    return r[nbr];
}

int main(void)
{
    int price[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    cout << solution(price, 6) << "\n";
}
