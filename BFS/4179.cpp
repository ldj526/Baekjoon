// 시작점이 두 종류일 때
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> r >> c;
	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;
	for (int i = 0; i < r; i++)
	{
		fill(dist1[i], dist1[i] + c, -1);
		fill(dist2[i], dist2[i] + c, -1);
	}
	for (int i = 0; i < r; i++)
		cin >> board[i];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'F') {
				Q1.push({ i, j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i, j });
				dist2[i][j] = 0;
			}
		}
	}
	while (!Q1.empty()) {		// 불에 대한
		auto cur = Q1.front(); Q1.pop();
		for (int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];		// 상하좌우 확인
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;		// 범위를 벗어나면 pass
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;	// board가 F가 아니거나 board가 벽이면 pass
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q1.push({ nx, ny });
		}
	}
	while (!Q2.empty()) {		// 지훈이에 대한
		auto cur = Q2.front(); Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];		// 상하좌우 확인
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) { 		// 범위를 벗어나면 성공
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;	// board가 J가 아니거나 board가 벽이면 pass
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;		// 지훈이 시간과 불의 전파시간 비교
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
}
