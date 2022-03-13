#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

bool compare(const string& a, const string& b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	int a_sum = 0, b_sum = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if ('0' <= a[i] && '9' >= a[i]) a_sum += a[i] - '0';
		if ('0' <= b[i] && '9' >= b[i]) b_sum += b[i] - '0';
	}
	if (a_sum != b_sum)
		return a_sum < b_sum;
	return a < b;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<string> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < n; i++)
		cout << vec[i] << '\n';
}
