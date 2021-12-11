#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[302][302];
int vis[302][302];
int t, n, a, b, c, d;
int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	queue<pair<int, int>> Q;
	while(t--){ 
		cin >> n;
		for (int i = 0; i < n; i++)
			fill(vis[i], vis[i] + n, -1);
		cin >> a >> b;
		Q.push({ a,b });
		vis[a][b] = 0;
		cin >> c >> d;
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (vis[nx][ny] >= 0) continue;
				vis[nx][ny] = vis[cur.X][cur.Y] + 1;
				Q.push({ nx, ny });
			}
		}
		cout << vis[c][d] << '\n';
	}
}
