#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v;
    int red_count = 0;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;

        cin >> temp;
        if (temp == "red")
            red_count++;
        else if (temp == "yellow")
            v.push_back(2);
        else if (temp == "green")
            v.push_back(3);
        else if (temp == "brown")
            v.push_back(4);
        else if (temp == "blue")
            v.push_back(5);
        else if (temp == "pink")
            v.push_back(6);
        else if (temp == "black")
            v.push_back(7);
    }
    int sum;
    if (!v.empty())
    {
        int max = *max_element(v.begin(), v.end());
        sum = max * (red_count + 1) + red_count;
        for (int i = 0; i < v.size(); i++)
            if (v[i] != max)
                sum += v[i];
    }
    else
    {
        sum = 1;
    }
    cout << sum << endl;
    

}