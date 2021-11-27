#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		string st;
		cin >> st;
		string tmp;
		deque<int> dq;
		for (int i = 0; i < st.length(); i++)   // tmp를 따로 만들지 않고 push를 하면 42같은 경우 4와 2로 나뉘어 들어가게 돼서 tmp
		{
			if (st[i] == '[')
				continue;
			else if (st[i] == ']' || st[i] == ',') {
				if (!tmp.empty()) {
					dq.push_back(stoi(tmp));
					tmp.clear();
				}
			}
			else
				tmp += st[i];
		}
		bool r = true; 
		bool d = true;    
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'R') {
				r = !r;
			}
			else if (s[i] == 'D') {
				if (r) {
					if (!dq.empty())
						dq.pop_front();
					else {
						d = false;
					}
				}
				else {
					if (!dq.empty())
						dq.pop_back();
					else {
						d = false;
					}
				}
			}
		}
		
		if (d) {    // d가 true인 경우 (error가 나지 않는 경우)
			cout << "[";
			if (r) {    // r(Reverse)가 되지 않은 경우 앞에서부터 출력
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
			}
			else {    // r(Reverse)가 되어 뒤에서부터 출력
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
			}
			cout << "]" << '\n';
		}
		else    // d가 false인 경우 (error인 경우)
			cout << "error" << '\n';
	}
}
