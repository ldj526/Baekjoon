#include <iostream>
#include <algorithm>
using namespace std;
long long arr[1000002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while (m--) {
		long long sum = 0;
		sort(arr, arr + n);
		sum = arr[0] + arr[1];
		arr[0] = sum;
		arr[1] = sum;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += arr[i];
	cout << ans;
}
