#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, a;
long long sum;

void ans(vector<int> vec) {
	while (vec.size() > 1) {
		sum += *(vec.end() - 1) * *(vec.end() - 2);
		vec.pop_back();
		vec.pop_back();
	}
	if (vec.size() == 1)
		sum += vec[0];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> plus;
	vector<int> minus;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1)
			sum++;
		else if (a > 0)
			plus.push_back(a);
		else
			minus.push_back(a);
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	reverse(minus.begin(), minus.end());
	ans(plus);
	ans(minus);
	cout << sum;
}
