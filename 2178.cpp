#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
string board[102];
int dist[102][102];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + m, -1);		// 거리를 나타내줄 배열
	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	dist[0][0] = 0;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];		// 상하좌우 확인
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;		// 범위를 벗어나면 pass
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;	// 이미 지나온 곳이거나 0인 곳은 pass
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << dist[n - 1][m - 1] + 1;
}
