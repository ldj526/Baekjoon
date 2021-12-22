#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int board[102][102];
int vis[102][102];
int N, maxcnt, maxheight;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int i, int j, int height) {
	queue<pair<int, int>> Q;
	vis[i][j] = 1;
	Q.push({ i, j });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[nx][ny] == 0 && board[nx][ny] > height) {
				vis[nx][ny] = 1;
				Q.push({ nx,ny });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			maxheight = max(board[i][j], maxheight);		// 최대 높이 구하기
		}
	}
	
	for (int height = 0; height <= maxheight; height++) {
		for (int i = 0; i < N; i++)
			fill(vis[i], vis[i] + N, 0);		// 방문한 곳 초기화

		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] > height && vis[i][j] == 0) {
					bfs(i, j, height);
					cnt++;
				}
			}
		}
		maxcnt = max(cnt, maxcnt);
	}
	cout << maxcnt;
}
