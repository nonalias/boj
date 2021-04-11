#include <iostream>
#include <algorithm>

using namespace std;

int intlen(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int check_pelin(int int_N, int size)
{
	string N = to_string(int_N);
	int intl = intlen(int_N);
	for (int i = 0; i < size - intl; i++)
		N = '0' + N;
	string sub, sub2;
	if (size % 2 == 0)
	{
		sub = N.substr(0, size / 2);
		sub2 = N.substr(size / 2, size / 2);
	}
	else
	{
		sub = N.substr(0, size / 2);
		sub2 = N.substr(size / 2 + 1, size / 2);
	}
	reverse(sub.begin(), sub.end());
	if (sub == sub2)
		return (1);
	return (0);
}

int main(void)
{
	string N;
	int		size;

	cin >> N;
	while (1)
	{
		if (N.size() == 1 && N[0] == '0')
			break;
		size = N.size();
		int i;
		for (i = 0; i < 900000000; i++)
		{
			if (check_pelin(stoi(N) + i, size))
				break;
		}
		cout << i << endl;
		cin >> N;
	}
}
