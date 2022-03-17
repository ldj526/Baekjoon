#include<iostream>
using namespace std;

int n, k;
int arr[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		cnt += k / arr[i];
		k %= arr[i];
	}
	cout << cnt;
}
