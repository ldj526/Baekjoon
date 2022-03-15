#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[302][3], num[302];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	if (n <= 1) {
		cout << num[1];
		return 0;
	}
	dp[1][1] = num[1];
	dp[1][2] = 0;
	dp[2][1] = num[2];
	dp[2][2] = num[1] + num[2];
	for (int i = 3; i <= n; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + num[i];
		dp[i][2] = dp[i - 1][1] + num[i];
	}
	cout << max(dp[n][1], dp[n][2]);
}
