#include <iostream>
using namespace std;
using ll = long long;

ll multi(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll ans = multi(a, b / 2, c);
	ans = ans * ans % c;
	if (b % 2 == 0) return ans;
	return ans * a % c;;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	cout << multi(a, b, c);
}
