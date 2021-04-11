#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b)
{
	double a_root, b_root;
	a_root = a.first * a.first + a.second * a.second;
	b_root = b.first * b.first + b.second * b.second;
	if (a_root < b_root)
		return (1);
	else if (a_root > b_root)
		return (0);
	else if (a_root == b_root)
		return a.first < b.first;
}

int main(void)
{
	int h, w;

	cin >> h >> w;
	while (!(h == 0 && w == 0))
	{
		vector<pair<int, int> > cand;
		for (int i = 1; i < 200; i++)
		{
			for (int j = 1; j < 200; j++)
			{
				if (i < j)
					cand.push_back(make_pair(i, j));
			}
		}
		sort(cand.begin(), cand.end(), cmp);
		/*
		for (int i = 0; i < cand.size(); i++)
		{
			cout << "(" << cand[i].first << ", "<< cand[i].second << ")"<< endl;	
		}
		*/
		for (int i = 0; i < cand.size(); i++)
			if (cmp(make_pair(h, w), cand[i]))
			{
				cout << cand[i].first << " " << cand[i].second << endl;
				break;
			}
		cin >> h >> w;
	}
}
