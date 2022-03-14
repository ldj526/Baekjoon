#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i] > b[j])
					cnt++;
				else
					break;
			}
		}
		cout << cnt << '\n';
	}
}
