#include <iostream>

using namespace std;

int main(void)
{
    string str;
    string ucpc = "UCPC";
    int cur = 0;

    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if (ucpc[cur] == str[i])
            cur++;
    }
    if (cur == 4)
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";
}