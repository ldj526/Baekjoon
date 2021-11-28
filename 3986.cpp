#include <iostream>
#include <stack>
using namespace std;

string s;
int n;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		stack<char> st;
		for (int j = 0; j < s.length(); j++)
		{
			if (j == 0) {
				st.push(s[j]);
			}
			else if (s[j] == 'A') {
				if (st.empty()||st.top() != 'A') {
					st.push(s[j]); 
				}
				else 
					st.pop();
			}
			else if (s[j] == 'B') {
				if (st.empty() || st.top() != 'B') {
					st.push(s[j]);
				}
				else 
					st.pop();
			}
		}
		if (st.empty()) {
			cnt++;
		}
	}
	cout << cnt;
}
