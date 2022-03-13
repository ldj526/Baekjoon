#include <iostream>
using namespace std;
int n, a;
int tmp[2000002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		tmp[a + 1000000]++;
	}
	for (int i = 0; i <= 2000000; i++)
	{
		while (tmp[i]--) {
			cout << i - 1000000 << '\n';
		}
	}
}
