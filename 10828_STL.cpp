#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	stack<int> st;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int a;
			cin >> a;
			st.push(a);
		}
		else if (s == "top") {
			if (!st.empty()) {
				cout << st.top() << '\n';
			}
			else
				cout << "-1" << '\n';
		}
		else if (s == "pop") {
			if (!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else
				cout << "-1" << '\n';
		}
		else if (s == "size") {
			cout << st.size() << '\n';
		}
		else if (s == "empty") {
			if (!st.empty()) {
				cout << "0" << '\n';
			}
			else
				cout << "1" << '\n';
		}
	}
}
