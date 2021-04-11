#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> check;
int draw_card[10];

void run(int n, int cards[], int k, string str)
{
	if (k == 0)
	{
		if (!check[str])
			check[str] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (draw_card[i] == 0)
		{
			draw_card[i] = 1;
			run(n , cards, k - 1, str + to_string(cards[i]));
			draw_card[i] = 0;
		}
	}
}

int main(void)
{
	int n, k;

	cin >> n >> k;
	int cards[n];
	for (int i = 0; i < n; i++)
		cin >> cards[i];
	run(n, cards, k, "");
	cout << check.size();
}
