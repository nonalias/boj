#include <iostream>

using namespace std;
int N, M;
int chess[50][50];

int go(int i, int j, int color)
{
	int sum = 0;
	for (int r = i; r < i + 8; r++)
	{
		for (int c = j; c < j + 8; c++)
		{
			if (c % 2 == 0 && color != chess[r][c])
				sum++;
			else if (c % 2 == 1 && color == chess[r][c])
				sum++;
		}
		color = !color;
	}
	return (sum);
}

int main(void)
{
	char temp;
	cin >> N >> M;
	int res = 987654321;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			if (temp == 'B')
				chess[i][j] = 0;
			else
				chess[i][j] = 1;
		}
	for (int i = 0; i + 7 < N; i++)
	{
		for (int j = 0; j + 7 < M; j++)
		{
			res = min(go(i, j, 0), res);
			res = min(go(i, j, 1), res);
		}
	}
	cout << res;
}
