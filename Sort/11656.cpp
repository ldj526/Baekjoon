#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string s, tmp;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<string> v;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		tmp = s.substr(i);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (auto a : v)
		cout << a << '\n';
}
