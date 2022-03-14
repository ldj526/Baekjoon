#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, c, num;
vector<pair<int, int>> v;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first > b.first;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		bool chk = false;
		cin >> num;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].second == num) {
				v[i].first++;
				chk = true;
				break;
			}
		}
		if(!chk) v.push_back({ 1, num });
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		while(v[i].first--)
			cout << v[i].second << ' ';
	}
}
