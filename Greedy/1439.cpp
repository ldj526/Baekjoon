#include <iostream>
using namespace std;
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	int cntZero = 0, cntOne = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[i + 1]) {
			if (s[i] == '0')
				cntZero++;
			else if (s[i] == '1')
				cntOne++;
		}
	}
	cout << min(cntZero, cntOne);
}
