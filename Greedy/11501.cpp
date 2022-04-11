#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
int stock[1000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> stock[i];
		int max = stock[n - 1];
		long long sum = 0;
		for (int i = n - 2; i >= 0; i--)
		{
			if (stock[i] > max) max = stock[i];
			sum += max - stock[i];
		}
		cout << sum << '\n';
	}
}
