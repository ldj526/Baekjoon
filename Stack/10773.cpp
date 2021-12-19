#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
	dat[pos++] = x;
}

void pop() {
	pos--;
}

int top() {
	return dat[pos - 1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	int sum = 0;
	cin >> k;
	while (k--) {
		int a;
		cin >> a;
		if (a != 0) {
			push(a);
		}
		else {
			pop();
		}
	}
	for (int i = 0; i < pos; i++)
	{
		sum += dat[i];
	}
	cout << sum;
}
