#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int run(int a, int b)
{
	int count;

	count = 0;
	for (int i = a; i <= b; i++)
	{
		int temp = i;
		if (temp == 0)
			count++;
		while (temp)
		{
			if (temp % 10 == 0)
				count++;
			temp  /= 10;
		}
	}
	return (count);
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << run(a, b) <<endl;
	}
}
