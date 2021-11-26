#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	head++;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int a;
			cin >> a;
			push(a);
		}
		else if (s == "pop") {
			if (tail - head == 0) {
				cout << "-1" << '\n';
			}
			else {
				cout << front() << '\n';
				pop();
			}
		}
		else if (s == "size") {
			cout << tail - head << '\n';
		}
		else if (s == "empty") {
			if (tail - head == 0) {
				cout << "1" << '\n';
			}
			else
				cout << "0" << '\n';
		}
		else if (s == "front") {
			if (tail - head == 0)
				cout << "-1" << '\n';
			else
				cout << front() << '\n';
		}
		else {
			if (tail - head == 0)
				cout << "-1" << '\n';
			else
				cout << back() << '\n';
		}
	}
}
