#include <iostream>

using namespace std;

int main(void)
{
    int count = 0;
    int people;
    string temp;

    cin >> people;
    cin >> temp;
    for (int i = 0; i < people; i++)
    {
        if (temp[i] == 'S')
            count++;
        else if (temp[i] == 'L')
        {
            count++;
            i++;
        }
    }
    count += 1;
    if (count > people)
        count = people;
    cout << count << endl;
}