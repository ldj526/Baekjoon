#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
string board[26];
int vis[26][26];
int N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	
	int cnt = 0;
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '0' || vis[i][j] == 1) continue;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;		// 들르는 자리 체크
			Q.push({ i, j });
			int area = 1;		// 처음 한 곳을 들르므로 넓이는 1부터 시작
			cnt++;		// 밑의 while문이 끝나면 중간에 끊겼다는 뜻이므로 개수 추가
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
					area++;
				}
			}
			vec.push_back(area);
		}
	}
	sort(vec.begin(), vec.end());		// 오름차순 정렬
	cout << cnt << '\n';
	for (int i : vec)
		cout << i << '\n';
}
