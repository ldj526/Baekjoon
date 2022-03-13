#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100005];
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int cnt = 1;
	long long mxval = -(1ll << 62) - 1;
	int mxcnt = 0;
	arr[n] = (1ll << 62) + 1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i - 1] == arr[i]) cnt++;
		else {
			if (cnt > mxcnt) {
				mxcnt = cnt;
				mxval = arr[i - 1];
			}
			cnt = 1;
		}
	}
	cout << mxval;
}
