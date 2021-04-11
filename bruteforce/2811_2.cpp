#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<pair<int, int> > sad;
int flower[100001];

void make_sad(int N)
{
	int index = 0, days = 0;
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (flag == 0 && temp < 0)
		{
			days = 1;
			index = i;
			flag = 1;
		}
		else if (flag == 1 && temp < 0)
			days++;
		else if ((flag == 1 && temp >= 0))
		{
			sad.push_back(make_pair(index, days));
			flag = 0;
		}
		if (i + 1 == N && temp < 0)
			sad.push_back(make_pair(index, days));
	}
}

void clear(int N)
{
	for (int i = 0; i < N; i++)
		flower[i] = 0;
}

int get_count(int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
		if (flower[i])
			count++;
	return (count);
}

int cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
		return (1);
	else if (a.second < b.second)
		return (0);
	else
		return (a.first > b.first);
}

int main(void)
{

	int N;
	int max = 0;
	int max_len;

	cin >> N;
	make_sad(N);
	//for (int i = 0; i < sad.size(); i++)
		//cout << sad[i].first << ", " << sad[i].second << endl;
	sort(sad.begin(), sad.end(), cmp);
	//for (int i = 0; i < sad.size(); i++)
		//cout << sad[i].first << ", " << sad[i].second << endl;
	if (sad.size())
		max_len = sad[0].second;
	for (int i = 0; i < sad.size() && sad[i].second == max_len; i++)
	{
		clear(N);
		for (int j = 0; j < sad.size(); j++)
		{
			if (i != j)
			{
				for (int k = 1; k <= 2 * sad[j].second; k++)
					if (sad[j].first - k >= 0)
						flower[sad[j].first - k] = 1;
			}
		}
		for (int k = 1; k <= 3 * sad[i].second; k++)
			if (sad[i].first - k >= 0)
				flower[sad[i].first - k] = 1;
		int temp;
		temp = get_count(N);
		if (temp > max)
			max = temp;
	}
	cout << max;
}
