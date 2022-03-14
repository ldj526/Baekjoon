#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<pair<int, string>> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	stable_sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < n; i++)
		cout << vec[i].first << ' ' << vec[i].second << '\n';
}

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int n, age;
string name;
vector<tuple<int, int, string>> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v.push_back({age, i, name });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << get<0> (v[i]) << ' ' << get<2> (v[i]) << '\n';
}
