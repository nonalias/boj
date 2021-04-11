#include <iostream>
#include <vector>

using namespace std;

int solution(int H, int W, int hostNbr)
{
    int address;
    int level;
    int room;

    if (hostNbr % H != 0)
    {
        room = hostNbr / H + 1;
        level = hostNbr % H;
    }
    else
    {
        room = hostNbr / H;
        level = H;
    }
    address = level * 100 + room;
    return (address);
}

int main(void)
{
    int tests;
    vector<int> result;

    cin >>tests;
    int W, H, hostNbr;
    while (tests)
    {
        cin >> H >> W >> hostNbr;
        result.push_back(solution(H, W, hostNbr));
        tests--;
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}