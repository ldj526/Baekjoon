#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mx = 0;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || vis[i][j]) continue;    // 0이거나 이미 방문한 곳이면 pass
			cnt++;                       // 1인 경우의 수
			queue<pair<int, int>> Q;
			vis[i][j] = 1;              // 1인 곳을 방문했다는 표시
			Q.push({ i, j });
			int area = 0;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				area++;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];     // 상하좌우 확인
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;     // 범위를 벗어난 곳이면 pass
					if (vis[nx][ny] || board[nx][ny] != 1) continue;        // 이미 방문했거나 1이 아닌곳 pass
					vis[nx][ny] = 1;          // 1인 곳을 방문했다는 표시
					Q.push({ nx, ny });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << cnt << '\n' << mx;
}
