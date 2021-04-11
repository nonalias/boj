#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int solution(int a, int b, int c)
{
    int count = 0;
    while (a + 1 != b || b + 1 != c)
    {
        count++;
        if (c - b > b - a)
        {
            a = b + 1;
            swap(&a, &b);
        }
        else
        {
            c = b - 1;
            swap(&c, &b);
        }
        
    }
    return (count);
}

int main(void)
{
    int a, b, c;

    while (cin >> a >> b >> c)
    {
        cout << solution(a, b, c) << "\n";
    }
}