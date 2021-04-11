#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(int A, int B, int n)
{
	if (A <= n && n <= B)
		return (1);
	return (0);
}

int main(void)
{
	int L, n;
	vector<int> S;
	cin >> L;
	int temp;
	for (int i = 0; i < L; i++)
	{
		cin >> temp;
		S.push_back(temp);
	}
	// 오름차순 정렬
	sort(S.begin(), S.end());
	cin >> n;
	
	// 어느 구간을 체크할지 확인하기 위해 index를 증가시켜줌
	int index = 0;
	while (S[index] < n)
		index++;

	// S[index - 1] + 1이 시작점, S[index] - 1가 끝점이다.
	int start, end;
	start = S[index - 1] + 1;
	end = S[index] - 1;
	int count = 0;
	
	// i 와 j는 시작점과 끝점의 모든 경우의 수를 접근하고,
	// check함수를 통해 좋은구간인지 확인한다.
	// i < j 이므로 i+1을 해 주었다.
	
	for (int i = start; i <= end - 1; i++)
		for (int j = i + 1; j <= end; j++)
			if (check(i, j, n))
				count++;
	cout << count;
}
