#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long cnt = 0;
	string s;
	cin >> s;
	stack<char> st;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (s[i - 1] == '(') {
				st.pop();
				cnt += st.size();
			}
			else {
				st.pop();
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}
