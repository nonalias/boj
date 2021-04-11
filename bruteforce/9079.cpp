#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int cases[8][3][2] = {
	//세로
		{
			{0, 0}, {1, 0}, {2, 0}
		},
		{
			{0, 1}, {1, 1}, {2, 1}
		},
		{
			{0, 2}, {1, 2}, {2, 2}
		},

		//가로
		{
			{0, 0}, {0, 1}, {0, 2}
		},
		{
			{1, 0}, {1, 1}, {1, 2}
		},
		{
			{2, 0}, {2, 1}, {2, 2}
		},

		//대각
		{
			{0, 0}, {1, 1}, {2, 2}
		},
		{
			{0, 2}, {1, 1}, {2, 0}
		}
};

int check(int table[3][3])
{
	int cmp = table[0][0];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (cmp != table[i][j])
				return (0);
	return (1);
}

void show_table(int table[3][3])
{
		cout << endl;
	for (int i = 0 ; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << table[i][j] << " ";
		cout << endl;
	}
		cout << endl;
}

vector<int> v;

void	run(int table[3][3], int visited[],int count, vector<int> roadmap)
{
	if (check(table))
	{
		/*
		for (int i = 0; i < roadmap.size(); i++)
			cout << roadmap[i] << ' ';
		cout << endl;
		*/
		v.push_back(count);
	}
	for (int i = 0; i < 8; i++)
	{
		if (visited[i] == 0)
		{
			table[cases[i][0][0]][cases[i][0][1]] = !table[cases[i][0][0]][cases[i][0][1]];
			table[cases[i][1][0]][cases[i][1][1]] = !table[cases[i][1][0]][cases[i][1][1]];
			table[cases[i][2][0]][cases[i][2][1]] = !table[cases[i][2][0]][cases[i][2][1]];
			visited[i] = 1;
			roadmap.push_back(i);
			run(table, visited, count + 1, roadmap);
			roadmap.erase(roadmap.begin() + roadmap.size() - 1);
			visited[i] = 0;
			table[cases[i][0][0]][cases[i][0][1]] = !table[cases[i][0][0]][cases[i][0][1]];
			table[cases[i][1][0]][cases[i][1][1]] = !table[cases[i][1][0]][cases[i][1][1]];
			table[cases[i][2][0]][cases[i][2][1]] = !table[cases[i][2][0]][cases[i][2][1]];

		}
	}
}

int main(void)
{
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		v.clear();
		int table[3][3];
		int visited[8] = {0, };
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			{
				char temp;
				cin >> temp;
				if (temp == 'T')
					table[j][k] = 1;
				else
					table[j][k] = 0;
			}
		//show_table(table);
		vector<int> roadmap;
		run(table, visited, 0, roadmap);
		if (v.size())
			cout << *min_element(v.begin(), v.end()) << endl;
		else
			cout << "-1" << endl;;
	}
}
