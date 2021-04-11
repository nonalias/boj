#include <iostream>

using namespace std;

int main(void)
{
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string N, M;
		int zero_count = 0;
		int one_count = 0; 
		cin >> N >> M;
		for (int j = 0; j < N.size(); j++)
		{
			if (N[j] != M[j])
			{
				if (N[j] == '0')
					zero_count++;
				else if (N[j] == '1')
					one_count++;
			}
		}
		cout << min(zero_count, one_count) + abs(zero_count - one_count) << endl;
	}
}
