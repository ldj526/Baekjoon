#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
string board[1002];
int visF[1002][1002];
int visS[1002][1002];
int t, w, h;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> h >> w;
		bool escape = false;
		queue<pair<int, int>> QF;
		queue<pair<int, int>> QS;
		for (int i = 0; i < w; i++)
		{
			fill(visF[i], visF[i] + h, -1);
			fill(visS[i], visS[i] + h, -1);
		}
		for (int i = 0; i < w; i++)
			cin >> board[i];
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				if (board[i][j] == '*') {
					QF.push({ i, j });
					visF[i][j] = 0;
				}else if (board[i][j] == '@') {
					QS.push({ i, j });
					visS[i][j] = 0;
				}
			}
		}
		while (!QF.empty()) {
			auto cur = QF.front(); QF.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
				if (visF[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				visF[nx][ny] = visF[cur.X][cur.Y] + 1;
				QF.push({ nx, ny });
			}
		}
		while ((!QS.empty()) && (!escape)) {
			auto cur = QS.front(); QS.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
					cout << visS[cur.X][cur.Y] + 1 << '\n';
					escape = true;
					break;
				}
				if (visS[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				if (visF[nx][ny] != -1 && visF[nx][ny] <= visS[cur.X][cur.Y] + 1) continue;
				visS[nx][ny] = visS[cur.X][cur.Y] + 1;
				QS.push({ nx,ny });
			}
		}
		if (!escape)
			cout << "IMPOSSIBLE" << '\n';
	}
}
