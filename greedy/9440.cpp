#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    vector<int> v_zero;
    vector<int> v;

    while (cin >> N && N != 0)
    {
        for (int i = 0; i < N; i++)
        {
            char temp;
            cin >> temp;
            if (temp == '0')
                v_zero.push_back(temp);
            else
                v.push_back(temp);
        }

        sort(v.begin(), v.end());
        string str1;
        string str2;
        str1 += v.front();
        v.erase(v.begin());
        str2 += v.front();
        v.erase(v.begin());
        while (!v_zero.empty())
        {
            str1 += v_zero.front();
            v_zero.erase(v_zero.begin());
            if (v_zero.empty())
                break;
            str2 += v_zero.front();
            v_zero.erase(v_zero.begin());
        }
        while (!v.empty())
        {
            if (str1.size() > str2.size())
            {
                str2 += v.front();
                v.erase(v.begin());
                if (v.empty())
                    break;
            }
            str1 += v.front();
            v.erase(v.begin());
        }
        int result = 0;
        result = stoi(str1) + stoi(str2);
        cout << result << endl;
    }
}