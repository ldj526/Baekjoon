#include <iostream>
using namespace std;
int n, m;
int arr[10];
bool isused[10];

void func(int a, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = a; i <= n; i++)
	{
		arr[k] = i;
		isused[i] = true;
		func(i, k + 1);
		isused[i] = false;
	}

}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(1, 0);
}
