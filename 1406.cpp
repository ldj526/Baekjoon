#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unsed = 1;

void insert(int addr, int num)
{
	dat[unsed] = num;
	pre[unsed] = addr;
	nxt[unsed] = nxt[addr];
	if (nxt[unsed] != 1)
		pre[nxt[addr]] = unsed;
	nxt[addr] = unsed;
	unsed++;
}

void erase(int addr)
{
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1)
		pre[nxt[addr]] = pre[addr];
}

void traverse() 
{
	int cur = nxt[0];
	while (cur != -1) {
		cout << char(dat[cur]);
		cur = nxt[cur];
	}
	cout << "\n\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	string s;
	cin >> s;
	int cursor = 0;
	for (auto a : s) {
		insert(cursor, a);
		cursor++;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		char c;
		cin >> c;
		switch (c) {
		case 'L':
			if (pre[cursor] != -1)
				cursor = pre[cursor];
			break;
		case 'D':
			if (nxt[cursor] != -1)
				cursor = nxt[cursor];
			break;
		case 'B':
			if (pre[cursor] != -1) {
				erase(cursor);
				cursor = pre[cursor];
			}
			break;
		case 'P':
			char d;
			cin >> d;
			insert(cursor, d);
			cursor = nxt[cursor];
			break;
		}
	}
	traverse();
}
