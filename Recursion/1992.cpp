#include <iostream>
using namespace std;
int n;
int board[65][65];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[i][j] != board[x][y])
				return false;
	return true;
}

void func(int x, int y, int z) {
	if (n == 1) {
		cout << board[x][y];
		return;
	}
	if (check(x, y, z)) {
		cout << board[x][y];
		return;
	}
	cout << "(";
	int a = z / 2;
	func(x, y, a);
	func(x, y + a, a);
	func(x + a, y, a);
	func(x + a, y + a, a);
	cout << ")";
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			board[i][j] = s[j] - '0';
	}
	func(0, 0, n);
}
