#include <iostream>

using namespace std;

int check[1000000];

void clear(int G)
{
	for (int i = 0; i < G; i++)
		check[i] = 0;
}

int check_overlap(int G)
{
	for (int i = 0; i < G; i++)
	{
		if (check[i] > 1)
			return (0);
	}
	return (1);
}

int main(void)
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int G;
		cin >> G;
		int list[300];
		for (int j = 0; j < G; j++)
			cin >> list[j];
		int j;
		for (j = 1; j < 999999; j++)
		{
			clear(j);
			for (int k = 0; k < G; k++)
				check[list[k] % j]++;
			if (check_overlap(j))
				break;
		}
		cout << j << endl;
	}
}
