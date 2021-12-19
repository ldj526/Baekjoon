#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
char board[102][102];
int vis[102][102];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push({ i, j });
	vis[i][j] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int idx = 0; idx < 4; idx++)
		{
			int nx = cur.X + dx[idx];
			int ny = cur.Y + dy[idx];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}
}

int number() {    // 구역 개수
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j]) {
				cnt++; 
				bfs(i, j);				
			}
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int normal_number = number();

	for (int i = 0; i < n; i++)     // 적록색약 개수를 세기위한 초기화
		fill(vis[i], vis[i] + n, false);
	for (int i = 0; i < n; i++)     // 적록색약이므로 적색을 녹색으로 바꿔줌
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'R')
				board[i][j] = 'G';
		}
	}
	int color_number = number();
	cout << normal_number << " " << color_number;
}
