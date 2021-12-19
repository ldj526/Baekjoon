#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
int board[52][52];
bool vis[52][52];
int t, m, n, k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<int, int>> q;

void bfs(int x, int y) {
	q.push({ x,y });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		vis[x][y] = true;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			board[b][a] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && !vis[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		for (int i = 0; i < n; i++)   // t가 1이 아닐 경우 board와 vis를 초기화
		{
			fill(board[i], board[i] + m, 0);
			fill(vis[i], vis[i] + m, false);
		}
	}
}
