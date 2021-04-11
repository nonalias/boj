#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int N;
	int i = 1;
	string ap;

	cin >> N;
	int k = 0;
	string temp;
	while (k < N)
	{
		temp = to_string(i);
		i++;
		k += temp.size();
	}
	//cout << ap << endl;
	//cout << ap[N - 1] << endl;
	cout << temp[k - N + 1] << endl;
}
