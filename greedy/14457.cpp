#include <iostream>

using namespace std;

int grid[11][11];

int main(void)
{
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char temp;
            cin >> temp;
            grid[i][j] = temp - '0';
        }
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (grid[i][j] == 1)
            {
                for (int a = 0; a <= i; a++)
                {
                    for (int b = 0; b <= j; b++)
                        grid[a][b] = grid[a][b] ? 0 : 1;
                }
                count++;
            }
        }
    }
    cout << count;
}