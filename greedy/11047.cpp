#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N, K;
	priority_queue<int> pq;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = pq.top();
		if (K / temp > 0)
		{
			count += K / temp;
			K %= temp;
		}
		pq.pop();
	}
	cout << count << endl;
}
