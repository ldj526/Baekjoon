// 시작점이 여러개일 때
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[1002][1002];
int vis[1002][1002];
int m, n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> m >> n;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)		// 시작점이 여러개이므로 시작점마다 큐에 넣어준다.
				Q.push({ i, j });
			if (board[i][j] == 0)		// -1, 1인곳은 vis가 0,  0인곳은 -1
				vis[i][j] = -1;
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];		// 상하좌우 확인
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;		// 범위를 벗어나면 pass
			if (vis[nx][ny] >= 0) continue;	// board가 -1이나 1인 곳은 pass
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;	// vis의 값은 날짜로 생각하면 된다.
			Q.push({ nx, ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] == -1) {		// board가 0인 곳이 남아 있다면
				cout << -1;
				return 0;
			}
			ans = max(ans, vis[i][j]);
		}
	}
	cout << ans;
}
