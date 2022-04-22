#include <iostream>
using namespace std;
int n;
int arr[102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int tmp = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (arr[i] >= tmp) {
			cnt += arr[i] - tmp + 1;
			arr[i] = tmp - 1;
		}
		tmp = arr[i];
	}
	cout << cnt;
}
