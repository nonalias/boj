#include <iostream>

using namespace std;

int main(void)
{
	int L, P, V;

	cin >> L >> P >> V;
	int i = 1;
	while (!(L == 0 && P == 0 && V == 0))
	{
		int count = 0;
		count = (V / P) * L;
		count += min(L, (V % P));
		cout << "Case " << i << ": " << count << endl;
		i++;
		cin >> L >> P >> V;
	}
}
