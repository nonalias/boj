#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return (1);
    else
    {
        return (0);
    }
    
}

int cmp2(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return (1);
    return (0);
}

int main(void)
{
    int N;
    vector<pair<int, int> > v;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), cmp);
    int second = v[0].first;
    sort(v.begin(), v.end(), cmp2);
    int first = v[0].second;
    if (second - first < 0)
        cout << 0;
    else
        cout << second - first;
}