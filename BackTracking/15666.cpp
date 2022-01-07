#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[10], arr2[10];
bool isused[10];

void func(int a, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = a; i < n; i++)
	{
		if (tmp != arr2[i]) {
			arr[k] = arr2[i];
			isused[i] = true;
			tmp = arr[k];
			func(i, k + 1);
			isused[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr2[i];
	sort(arr2, arr2 + n);
	func(0, 0);
}
