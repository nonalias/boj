#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int _max = -1;
    int count;

    cin >> N;
    int height[30001] = {0, };
    for (int i = 0; i < N; i++)
        cin >> height[i];
    for (int i = 0; i < N; i++)
    {
        count = 0;
        for (int j = i + 1; j < N; j++)
        {
            if (height[i] > height[j])
            {
                count++;
            }
            else
                break;
        }
        if (_max < count)
            _max = count;
    }
    cout << _max;
}