#include <iostream>
using namespace std;
int n;
int board[130][130];
int cnt[2];	// 0, 1 담을 배열

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[i][j] != board[x][y])
				return false;
	return true;
}

void func(int x, int y, int z) {
	if (check(x, y, z)) {
		cnt[board[x][y]] += 1;
		return;
	}
	int a = z / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			func(x + i * a, y + j * a, a);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	func(0, 0, n);
	for (int i = 0; i < 2; i++)
		cout << cnt[i] << '\n';
}
