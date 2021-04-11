#include <iostream>

using namespace std;

int solution(int nbr)
{
    int level;

    level = 1;
    nbr--;
    while (nbr > 0)
    {
        nbr -= (level * 6);
        level++;
    }
    return (level);
}

int main(void)
{
    int     nbr;

    cin >> nbr;
    cout << solution(nbr);
}