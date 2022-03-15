#include <iostream>
#include <algorithm>
using namespace std;
int t, num;
int dp[1000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (t--) {
		cin >> num;
		for (int i = 4; i < 11; i++)
			dp[i] = dp[i - 2] + dp[i - 1] + dp[i - 3];
		cout << dp[num] << '\n';
	}
}
