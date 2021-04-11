#include <iostream>

using namespace std;

int main(void)
{
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string N, M;
		cin >> N >> M;
		int count = 0;
		for (int j = 0; j < N.size(); j++)
		{
			if (N[j] != M[j])
			{
				for (int k = j; k < N.size(); k++)
				{
					if (N[k] != M[k] && N[k] != N[j])
					{
						int temp = N[j];
						N[j] = N[k];
						N[k] = temp;
						count++;
						break;
					}
				}
				if (N[j] != M[j])
					count++;
			}
		}
		cout << count << endl;
	}
}
