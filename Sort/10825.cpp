#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
string name;
int n, kr, en, ma;
vector < tuple<int, int, int, string>> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> kr >> en >> ma;
		v.push_back({ -kr, en, -ma, name });
	}
	sort(v.begin(), v.end());
	for (auto a : v)
		cout << get<3> (a) << '\n';
}

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

struct STU {
	string name;
	int kr, en, ma;
};

bool compare(STU a, STU b) {
	if (a.kr == b.kr && a.en == b.en && a.ma == b.ma)
		return a.name < b.name;
	if (a.kr == b.kr && a.en == b.en)
		return a.ma > b.ma;
	if (a.kr == b.kr)
		return a.en < b.en;
	return a.kr > b.kr;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<STU> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].name >> v[i].kr >> v[i].en >> v[i].ma;
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
		cout << v[i].name << '\n';
}
