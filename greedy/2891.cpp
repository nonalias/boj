#include <iostream>
#include <vector>


using namespace std;

int main(void)
{
	int N, S, R;

	// N -> 팀의 수
	// S -> 카약 손상된 팀의 수
	// R -> 여분의 카약을 가져온 팀의 수
	cin >> N >> S >> R;

	vector<int> damaged;
	vector<int> spare;

	for (int i = 0; i < S; i++)
	{
		int temp;
		cin >> temp;
		damaged.push_back(temp);
	}
	for (int i = 0; i < R; i++)
	{
		int temp;
		cin >> temp;
		spare.push_back(temp);
	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < R; j++)
		{
			if (damaged[i] - 1 == spare[j] || damaged[i] + 1 == spare[j])
			{
				damaged[i] = 0;
				spare[j] = 0;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < S; i++)
		if (damaged[i] != 0)
			count++;
	cout << count << endl;
}
