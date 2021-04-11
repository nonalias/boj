#include <iostream>

using namespace std;

void solution(string S)
{
	int answer = 0;

	// min (0의 구역, 1의 구역)
	int zero, one;

	zero = 0; one = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '0')
		{
			zero++;
			while (S[i] == '0')
				i++;
			i--;
		}
		else
		{
			one++;
			while (S[i] == '1')
				i++;
			i--;
		}
	}
	cout << min(zero, one) << endl;
}

int main(void)
{
	string str;
	cin >> str;
	solution(str);
	return (0);
}
