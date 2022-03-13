#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector <long long> v;
string s;
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(stoll(s));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
}
