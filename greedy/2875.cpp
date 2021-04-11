#include <iostream>

using namespace std;

int main(void)
{
	int N, M, K;

	cin >> N >> M >> K;
	while (K)
	{
		if (2 * M <= N)
			N--;
		else
			M--;
		K--;
	}
	int count = 0;
	while (N >= 2 && M >= 1)
	{
		count++;
		N -= 2;
		M -= 1;
	}
	cout << count;
}
