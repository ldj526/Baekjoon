#include <iostream>
#include <stack>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	stack<char> st;
	int sum = 0;
	int cnt = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') {
			cnt *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[') {
			cnt *= 3;
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '(')
				sum += cnt;
			st.pop();
			cnt /= 2;
		}
		else {
			if (st.empty() || st.top() != '[') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '[')
				sum += cnt;
			st.pop();
			cnt /= 3;
		}
	}
	if (st.empty())
		cout << sum;
	else
		cout << 0;
}
