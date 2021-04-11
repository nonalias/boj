#include <iostream>
#include <vector>

using namespace std;

int check_list[200][200];

int check(int i, int j, int k)
{
	if (check_list[i][j] != 1 && check_list[j][k] != 1
			&& check_list[i][k] != 1)
		return (1);
	return (0);
}

int run(int N)
{
	int count = 0;
	for (int i = 0; i < N - 2; i++)
		for (int j = i + 1; j < N - 1; j++)
			for (int k = j + 1; k < N; k++)
				if (check(i, j, k))
					count++;
	return (count);
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	vector<pair<int, int> > sep;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (a < b)
			check_list[a][b] = 1;
		else
			check_list[b][a] = 1;
	}
	cout << run(N) << endl;
}
