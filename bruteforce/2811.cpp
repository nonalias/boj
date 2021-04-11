#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp_pair(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
		return (1);
	else if (a.second == b.second)
		return (a.first > b.first);
	else
		return (0);
}


int tempa[100000];
int flower[100000];
int cand_flower[100000];

int get_count(int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
		if (cand_flower[i] == 1)
			count++;
	return (count);
}

void copy(int N)
{
	for (int i = 0; i < N; i++)
		cand_flower[i] = flower[i];
}

vector<pair<int, int> > sad;

int main(void)
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		tempa[i] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		int fir, sec = 0;
		if (tempa[i] < 0)
			fir = i;
		while (i < N && tempa[i] < 0)
		{
			i++;
			sec++;
		}
		if (i - 1 >= 0)
			if (tempa[i - 1] < 0)
				sad.push_back(make_pair(fir, sec));
	}
	sort(sad.begin(), sad.end(), cmp_pair);
	/*
	for (int i = 0; i < sad.size(); i++)
	{
		cout << sad[i].first << ", " << sad[i].second << endl;
	}
	*/
	/*jjjjjjjjjj
	int last = 0;
	while (sad[0].second == sad[last].second)
		last++;
	// 2T일만큼 공통적으로 넣는다
	for (int i = last; i < sad.size(); i++)
	{
		for (int j = 1; j <= sad[i].second * 2; j++)
		{
			flower[sad[i].first - j] = 1;
		}
	}
	// 3T를 넣을 후보를 탐색하고, 가장 높은 count를 return하면 끗
	for (int i = 0; i < last; i++)
	{
		copy(N);
	}
	*/
	int mx = -1;
	for (int i = 0; i < sad.size(); i++)
	{
		copy(N);
		for (int j = 0; j < sad.size(); j++)
			if (j != i)
			{
				for (int k = 1; k <= sad[j].second * 2; k++)
				{
					if (sad[j].first - k >= 0)
						cand_flower[sad[j].first - k] = 1;
				}
			}
		for (int k = 1; k <= sad[i].second * 3; k++)
		{
			if (sad[i].first - k >= 0)
				cand_flower[sad[i].first - k] = 1;
		}
		int temp = get_count(N);
		if (temp > mx)
			mx = temp;
	}
	cout << mx;
}

