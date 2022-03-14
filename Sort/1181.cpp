#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <string> v;
string s;
int n;

bool compare(const string& a, const string& b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	return a < b;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}
