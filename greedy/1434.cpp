#include <iostream>

using namespace std;

int main(void)
{
    int boxCnt, bookCnt;
    cin >> boxCnt >> bookCnt;

    int box[boxCnt];
    int book[bookCnt];
    int result;

    for (int i = 0; i < boxCnt; i++)
        cin >> box[i];
    for (int i = 0; i < bookCnt; i++)
        cin >> book[i];

    int cur = 0;
    int j = 0;
    while (j != bookCnt)
    {
        if (box[cur] - book[j] < 0)
            cur++;
        else
        {
            box[cur] -= book[j];
            j++;
        }
    }
    result = 0;
    for (int i = 0; i < boxCnt; i++)
        result += box[i];
    cout << result << "\n";
}