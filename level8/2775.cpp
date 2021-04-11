#include <iostream>
#include <vector>

using namespace std;

int     solution(int k, int n)
{
    vector<int> prev;
    vector<int> curr;

    for(int i = 0; i < n; i++)
        prev.push_back(i + 1);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
    }
}

int main(void)
{
    int tests;
    vector<int> result;

    cin >> tests;
    while (tests)
    {
        int k, n;
        cin >> k >> n;
        result.push_back(solution(k, n));
        tests--;
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}