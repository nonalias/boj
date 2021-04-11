#include <iostream>
#include <vector>

#define Alice 0
#define Bob 1
#define Me 2
using namespace std;

int main(void)
{
    int piz_count, my_index;
    int matches;
    cin >> piz_count >> my_index;
    vector<int> v;

    for (int i = 0; i < piz_count; i++)
    {
        int temp;
        string str_temp;
        cin >> temp >> str_temp;
        v.push_back(temp);
    }
    my_index--;
    matches = v[my_index];
    int roundrobin = 0;
    while (v.size() > 1)
    {
        switch (roundrobin)
        {
            case Alice:
                v.erase(v.begin() + (v.size() - 1));
                break;
            case Bob:
                v.erase(v.begin());
                my_index--;
                break;
            case Me:
                if (my_index < v.size() - 1 - my_index)
                {
                    if (my_index + 1 > v.size() - 1)
                    {
                        cout << "NO";
                        return (0);
                    }
                    v.erase(v.begin() + (my_index + 1));
                }
                else
                {
                    if (my_index < 1)
                    {
                        cout << "NO";
                        return (0);
                    }
                    v.erase(v.begin() + (my_index - 1));
                    my_index--;
                }
        }
        roundrobin++;
        roundrobin %= 3;
    }
    //cout << v[0] << endl;
    if (v[0] == matches)
        cout << "YES";
    else
        cout << "NO";
}