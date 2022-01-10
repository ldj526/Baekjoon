#include <iostream>
#include <algorithm>
using namespace std;
int k;
int S1[15], S2[15];
bool isused[15];
void func(int n, int a) {
	if (a == 6) {
		for (int i = 0; i < 6; i++)
			cout << S1[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = n; i < k; i++)
	{
		if (!isused[i] && tmp != S2[i]) {
			S1[a] = S2[i];
			isused[i] = true;
			func(i + 1, a + 1);
			isused[i] = false;
		}
	}

}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
			cin >> S2[i];
		func(0, 0);
		cout << '\n';
	}
}
