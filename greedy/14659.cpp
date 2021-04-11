#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int height[N];
    int count[30001] = {0, };

    for (int i = 0; i < N; i++)
        cin >> height[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (height[i] > height[j])
            {
                count[i]++;
            }
            else
            {
                break;
            }
            
        }
    }
    int max = -1;
    for (int i = 0; i < N; i++)
    {
        if (count[i] > max)
            max = count[i];
    }
    cout << max;
}