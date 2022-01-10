#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char arr2[20];
int arr1[20];
bool isused[20];
bool vow(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}
void func(int a, int k) {
	if (k == l) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < l; i++)
		{
			if (vow(arr2[arr1[i]])) 
				cnt1++;
			else 
				cnt2++;
		}
		if (cnt1 >= 1 && cnt2 >= 2) {
			for (int i = 0; i < l; i++)
				cout << arr2[arr1[i]];
			cout << '\n';
		}
		return;
	}
	int tmp = 0;
	for (int i = a; i < c; i++)
	{
		if (!isused[i] && tmp != arr2[i]) {
			arr1[k] = i;
			isused[i] = true;
			func(i + 1, k + 1);
			isused[i] = false;
		}
	}

}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> arr2[i];
	sort(arr2, arr2 + c);
	func(0, 0);
}
