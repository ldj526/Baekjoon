#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int dp[100002];
int a[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = dp[i - 1] + a[i];
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << '\n';
	}
}
