#include <iostream>

using namespace std;

int check(string temp, string lookFor)
{
	int find;
	for (int i = 0; i < temp.size(); i++)
	{
		find = 1;
		for (int j = 0; j < lookFor.size(); j++)
		{
			if (temp[(i + j) % temp.size()] != lookFor[j])
				find = 0;
		}
		if (find)
			return (1);
	}
	return (0);
}

int main(void)
{
	int N;
	int count = 0;
	string lookFor;

	cin >> lookFor;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		if (check(temp, lookFor))
			count++;
	}
	cout << count;
}
