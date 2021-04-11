#include <iostream>

using namespace std;

int main(void)
{
	// N -> 세로, M -> 가로
	int N, M;
	cin >> N >> M;

	int count;
	if (N == 1)
		count = 1;
	else if (N == 2)
		count = min(4, (M + 1) / 2);
	else
	{
		if (M >= 7)
		{
			count = M - 5;
			count += 3;
		}
		else
			count = min(4, M);
	}
	cout << count;
}
