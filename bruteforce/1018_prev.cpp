#include <iostream>

using namespace std;

char chess[50][50];

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, 1, -1};
int N, M;

int check_isolated_color(int x, int y)
{
	int new_x;
	int	new_y;

	for (int i = 0; i < 4; i++)
	{
		new_x = x + move_x[i];
		new_y = y + move_y[i];
		//cout << "new_x : " << new_x << "new_y : " << new_y << endl;
		if (!(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M))
		{
			if (chess[new_x][new_y] != chess[x][y])
				return (0);
		}
	}
	return (1);
}

int	go(int start[2], int end[2])
{
	int sum;

	sum = 0;
	for (int i = start[0]; i < start[0] + 8; i++)
		for (int j = start[1]; j < start[1] + 8; j++)
		{
			//cout << i << ", "<< j << endl;
			if (check_isolated_color(i, j))
			{
				sum++;
				//sum += check_isolated_color(i, j);
			}
		}
	return (sum);
}

int main(void)
{

	cin >> N >> M;
	int min = 987654321;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> chess[i][j];
	int start[2] = {0, 0};
	int end[2] = {7, 7};
	for (int i = 0; i + 7 < N; i++)
	{
		start[0] = i;
		end[0] = i + 7;
		for (int j = 0; j + 7 < M; j++)
		{
			start[1] = j;
			end[1] = j + 7;
			//cout << "hello\n";
			int temp = go(start,end);
			if (min > temp)
				min = temp;
		}
	}
	cout << min;
}
