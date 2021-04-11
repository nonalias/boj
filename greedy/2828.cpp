#include <iostream>

using namespace std;

int main(void)
{
    int N, M;
    int apple_count;
    int move_count = 0;
    cin >> N >> M;
    M -= 1;
    cin >> apple_count;
    int apple[apple_count];
    for (int i = 0; i < apple_count; i++)
    {
        cin >> apple[i];
    }
    int left, right;
    left = 1;
    right = left + M;
    for (int i = 0; i < apple_count; i++)
    {
        if (left <= apple[i] && apple[i] <= right)
        {
            continue;
            //ok
        }
        else if (left > apple[i])
        {
            move_count += (left - apple[i]);
            left -= (left - apple[i]);
            right = left + M;
        }
        else if (right < apple[i])
        {
            move_count += (apple[i] - right);
            right += (apple[i] - right);
            left = right - M;
        }
    }
    cout << move_count;
}