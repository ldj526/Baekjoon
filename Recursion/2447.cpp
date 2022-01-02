#include <iostream>
using namespace std;
int n;
char board[2200][2200];

void func(int n, int x, int y){
	if (n == 1) {
		board[x][y] = '*';
		return;
	}
	int a = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			func(a, x + a * i, y + a * j);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, ' ');
	func(n, 0, 0);
	for (int i = 0; i < n; i++)
		cout << board[i] << '\n';
}
