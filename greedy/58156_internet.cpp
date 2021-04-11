#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char nums[15];

string solution(int n, int start) {
	string answer = "";
	for (int i = start; i < n; i += 2) {
		answer += nums[i];
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (1) {
		int n; cin >> n;
		int cnt = 0;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			if (nums[i] == '0') cnt++;
		}
		sort(nums, nums + n);

		if (cnt == 1) {
			nums[0] = nums[cnt];
			nums[cnt] = '0';
		}
		else if (cnt >= 2) {
			nums[0] = nums[cnt]; nums[1] = nums[cnt + 1];
			nums[cnt] = '0'; nums[cnt + 1] = '0';
		}

		string x = "", y = "";
		x = solution(n, 0);
		y = solution(n, 1);

		int answer = 0;
		answer = stoi(x) + stoi(y);
		cout << answer << '\n';
	}
}
