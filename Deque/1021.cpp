#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int n, m, idx;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)    // 덱에 n개의 원소 넣기
		dq.push_back(i);
	while (m--) {
		int a;
		cin >> a;
		for (int i = 0; i < dq.size(); i++)   // 찾으려는 숫자의 index 값 찾아주기
		{
			if (dq[i] == a) {
				idx = i;
				break;
			}
		}
		if (idx < dq.size() - idx) {    // 왼쪽으로 한칸 이동
			while (dq.front() != a) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		else {
			while (dq.front() != a) {   // 오른쪽으로 한칸 이동
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		dq.pop_front();   // 일치하는 숫자 나오면 pop
	}
	cout << cnt;
}
