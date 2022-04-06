#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, sm, sd, em, ed;
vector <pair<int, int>> vec;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sm >> sd >> em >> ed;
		vec.push_back({ sm * 100 + sd, em * 100 + ed });
	}
	sort(vec.begin(), vec.end());
	int t = 301;
	int ans = 0;
	while (t < 1201) {
		int nxt = t;
		for (int i = 0; i < n; i++)
		{
			if (vec[i].first <= t && vec[i].second > nxt)
				nxt = vec[i].second;
		}
		if (nxt == t) {
			cout << 0;
			return 0;
		}
		ans++;
		t = nxt;
	}
	cout << ans;
}
