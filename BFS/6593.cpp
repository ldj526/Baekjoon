#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int L, R, C;
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		queue<tuple<int, int, int>> Q;
		char board[32][32][32];
		int vis[32][32][32];
		bool isEscape = false;
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++)
				fill(vis[i][j], vis[i][j] + C, 0);

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {	// 현재 위치일 때
						Q.push({ i,j,k });
						vis[i][j][k] = 0;
					}
					else if (board[i][j][k] == '.')		// 비어있는 칸. 통행가능한 곳
						vis[i][j][k] = -1;
				}
			}
		}
		while (!Q.empty()) {
			if (isEscape) break;
			auto cur = Q.front(); Q.pop();
			int curX, curY, curZ;
			tie(curX, curY, curZ) = cur;
			for (int dir = 0; dir < 6; dir++)
			{
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				int nz = curZ + dz[dir];
				if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;	// 범위 벗어났을 때
				if (board[nx][ny][nz] == '#' || vis[nx][ny][nz] > 0) continue;	// 벽이거나 이미 지나온 길일 때
				vis[nx][ny][nz] = vis[curX][curY][curZ] + 1;
				if (board[nx][ny][nz] == 'E') {	// 탈출구를 찾았을 때
					cout << "Escaped in " << vis[nx][ny][nz] << " minute(s).\n";
					isEscape = true;
					break;
				}
				Q.push({ nx,ny,nz });
			}
		}
		while (!Q.empty()) Q.pop();
		if (!isEscape) cout << "Trapped!" << '\n';
	}
}
