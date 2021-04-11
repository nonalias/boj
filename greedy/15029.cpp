#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;

    cin >> N;
    priority_queue<int> pq;
    int red_count = 0;
    for (int i = 0; i < N; i++)
    {
        string tmp_str;
        int temp;
        cin >> tmp_str;
        if (tmp_str == "red")
        {
            red_count++;
            continue;
        }
        else if (tmp_str == "yellow")
            temp = 2;
        else if (tmp_str == "green")
            temp = 3;
        else if (tmp_str == "brown")
            temp = 4;
        else if (tmp_str == "blue")
            temp = 5;
        else if (tmp_str == "pink")
            temp = 6;
        else if (tmp_str == "black")
            temp = 7;
        pq.push(temp);
    }
    int sum;
    if (!pq.empty())
    {
        sum = pq.top() * (red_count + 1) + red_count;
        pq.pop();
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    else
        sum = 1;

    cout << sum;
}