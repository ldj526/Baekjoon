#include <iostream>
#include <algorithm>
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

void eerase(int addr)
{

}

void traverse() 
{
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur] << ' ';
		cur = nxt[cur];
	}
	cout << "\n\n";
}

void insert_test()
{

}

void erase_test()
{

}

int main(void)
{
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
}