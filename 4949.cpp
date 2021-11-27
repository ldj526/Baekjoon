#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		string s;
		getline(cin, s);    // #include <string> 필요. 
		bool print = true;
		stack<char> st;
		if (s == ".")
			break;
		for (auto c : s) {
			if (c == '(' || c == '[') {
				st.push(c);
			}
			else if (c == ')') {
				if (st.empty() || st.top() != '(') {
					print = false;
					break;
				}
				st.pop();
			}
			else if (c == ']') {
				if (st.empty() || st.top() != '[') {
					print = false; 
					break;
				}
				st.pop();
			}
		}
		if (!st.empty())
			print = false;
		if (print)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
}
