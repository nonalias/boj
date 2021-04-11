#include <iostream>

using namespace std;

int check_x[10];
int check_y[10];

int dx[2] = {1, -1};
int dy[2] = {-1, 1};

void check_clear()
{
	for (int i = 0; i < 10; i++)
	{
		check_x[i] = 0;
		check_y[i] = 0;
	}
}

int		is_friend(string x, string y)
{
	check_clear();
	//cout << "x : " << x << ", y : " << y << endl;
	for (int i = 0; i < x.size(); i++)
		check_x[x[i] - '0'] = 1;
	for (int i = 0; i < y.size(); i++)
	{
		check_y[y[i] - '0'] = 1;
	}
	for (int i = 0; i < 10; i++)
	{
		if (check_x[i] != check_y[i])
			return (0);
	}
	return (1);
}

char	char_sum(char c, int i)
{
	if (c == '9' && i == 1)
		return ('0');
	if (c == '0' && i == -1)
		return ('9');
	return (c + i);
}

int		is_almost_friend(string x, string y)
{
	string temp;
	temp = x;
	for (int i = 0; i < x.size() - 1; i++)
	{
		// 1더하고
		temp[i] = char_sum(temp[i], 1);
		temp[i + 1] = char_sum(temp[i + 1], -1);
		if (is_friend(temp, y))
			return (1);
		temp[i] = char_sum(temp[i], -1);
		temp[i + 1] = char_sum(temp[i + 1], 1);

		temp[i] = char_sum(temp[i], -1);
		temp[i + 1] = char_sum(temp[i + 1], 1);
		if (temp[0] != '0')
			if (is_friend(temp, y))
				return (1);
		temp[i] = char_sum(temp[i], 1);
		temp[i + 1] = char_sum(temp[i + 1], -1);
	}
	temp = y;
	for (int i = 0; i < y.size() - 1; i++)
	{
		// 1더하고
		temp[i] = char_sum(temp[i], 1);
		temp[i + 1] = char_sum(temp[i + 1], -1);
		if (is_friend(x, temp))
			return (1);
		temp[i] = char_sum(temp[i], -1);
		temp[i + 1] = char_sum(temp[i + 1], 1);

		temp[i] = char_sum(temp[i], -1);
		temp[i + 1] = char_sum(temp[i + 1], 1);
		if (temp[0] != '0')
			if (is_friend(x, temp))
				return (1);
		temp[i] = char_sum(temp[i], 1);
		temp[i + 1] = char_sum(temp[i + 1], -1);
	}
	return (0);
}

void	run(string x, string y)
{
	if (is_friend(x, y))
		cout << "friends\n";
	else if (is_almost_friend(x, y))
		cout << "almost friends\n";
	else 
		cout << "nothing\n";
}

int main(void)
{
	string x, y;
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		run(x, y);
	}
}
