#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int T;
	int J, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> J >> N;
		priority_queue<int> pq;
		int count = 0;
		for (int j = 0 ; j < N; j++)
		{
			int x, y;
			cin >> x >> y;
			pq.push(x * y);
		}
		while (J > 0)
		{
			J -= pq.top();
			pq.pop();
			count++;
		}
		cout << count << endl;
	}
}
