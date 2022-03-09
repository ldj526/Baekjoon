#include <iostream>
#include <algorithm>
using namespace std;
int n;

bool compareX(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
bool compareY(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	pair<int, int> p[100002];
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	stable_sort(p, p + n, compareX);
	stable_sort(p, p + n, compareY);
	for (int i = 0; i < n; i++)
		cout << p[i].first << ' ' << p[i].second << '\n';
}
