#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[1000005], pre[1000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			pre[i] = i / 3;
		}
	}
	cout << dp[n] << '\n';
	while (true) {
		cout << n << ' ';
		if (n == 1) break;
		n = pre[n];
	}
}
