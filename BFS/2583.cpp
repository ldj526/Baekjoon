#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[102][102];
int vis[102][102];
int M, N, K;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> K;
	while (K--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				board[i][j] = 1;
	}
	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1 || vis[i][j] == 1)
				continue;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;		// 들르는 자리 체크
			int area = 1;		// 처음 한 곳을 들르므로 넓이는 1부터 시작
			Q.push({ i, j });
			cnt++;		// 밑의 while문이 끝나면 중간에 끊겼다는 뜻이므로 개수 추가
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;		// 범위를 벗어나면 pass
					if (board[nx][ny] == 1 || vis[nx][ny] == 1) continue;		// 아닌곳을 세야 하므로 영역이거나 방문한 곳이면 pass
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
					area++;
				}
			}
			ans.push_back(area);
		}
	}
	sort(ans.begin(), ans.end());		// 오름차순 정렬

	cout << cnt << '\n';
	for (int i : ans)
		cout << i << ' ';
}
