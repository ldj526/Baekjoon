#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
		cout << vec[i].first << ' ' << vec[i].second << '\n';
}
