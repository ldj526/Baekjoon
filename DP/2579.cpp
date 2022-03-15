#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[302], num[305];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	if (n <= 1) {
		cout << sum;
		return 0;
	}
	dp[1] = num[1];
	dp[2] = num[2];
	dp[3] = num[3];
	for (int i = 1; i <= n - 1; i++)
		dp[i] = min(dp[i - 2], dp[i - 3]) + num[i];
	cout << sum - min(dp[n - 1], dp[n - 2]);
}
