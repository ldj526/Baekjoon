#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
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
		if (s == "push_front") {
			int a;
			cin >> a;
			push_front(a);
		}
		else if (s == "push_back") {
			int a;
			cin >> a;
			push_back(a);
		}
		else if (s == "pop_front") {
			if (tail - head == 0)
				cout << "-1" << '\n';
			else {
				cout << front() << '\n';
				pop_front();
			}
		}
		else if (s == "pop_back") {
			if (tail - head == 0)
				cout << "-1" << '\n';
			else {
				cout << back() << '\n';
				pop_back();
			}
		}
		else if (s == "size") {
			cout << tail - head << '\n';
		}
		else if (s == "empty") {
			if (tail - head == 0)
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (s == "front") {
			if (tail - head == 0)
				cout << "-1" << '\n';
			else
				cout << front() << '\n';
		}
		else if (s == "back") {
			if (tail - head == 0)
				cout << "-1" << '\n';
			else 
				cout << back() << '\n';
		}
	}
}
