#include <iostream>
#include <algorithm>
using namespace std;
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	pair<int, int> a[100005];
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i].second >> a[i].first;
	sort(a, a + n);
	int cnt = 0;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (t > a[i].second) continue;
		cnt++;
		t = a[i].first;
	}
	cout << cnt;
}
