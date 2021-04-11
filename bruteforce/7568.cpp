#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<pair<int, int> > v;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	int count;
	for (int i = 0; i < N; i++)
	{
		count = 0;
		for (int j = 0; j < N; j++)
		{
			if (i != j)
				if (v[i].first < v[j].first && v[i].second < v[j].second)
					count++;
		}
		cout << count + 1 << " ";
	}
}
