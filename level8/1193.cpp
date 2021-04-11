#include <iostream>

using namespace std;

string     solution(int input)
{
    int left;
    int right;
    int temp;
    int level;

    level = 1;
    temp = input;
    while ((temp -= level) > 0)
    {
        input = temp;
        level++;
    }
    if (level % 2 == 0)
    {
        left = 1;
        right = level;
        while (input > 1)
        {
            left++;
            right--;
            input--;
        }
    }
    else
    {
        left = level;
        right = 1;
        while (input > 1)
        {
            left--;
            right++;
            input--;
        }
    }
    return ("" + to_string(left) + "/" + to_string(right));
}

int main(void)
{
    int input;

    cin >> input;
    cout << solution(input);
}