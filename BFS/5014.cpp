#include <iostream>
#include <queue>
using namespace std;
int dist[1000002];
int F, S, G, U, D;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> F >> S >> G >> U >> D;
	fill(dist + 1, dist + F + 1, -1);
	queue<int> Q;
	dist[S] = 0;
	Q.push(S);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (auto nxt : { cur - D, cur + U })
		{
			if (nxt > F || nxt <= 0 || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	if (dist[G] == -1)
		cout << "use the stairs";
	else
		cout << dist[G];
}
