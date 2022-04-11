#include <iostream>
#include <algorithm>
using namespace std;
string s;
int sum, tmp;
int sign = 1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-') {
			sum += tmp * sign;
			if (s[i] == '-') sign = -1;
			tmp = 0;
		}
		else {
			tmp *= 10;
			tmp += s[i] - '0';
		}
	}
	sum += tmp * sign;
	cout << sum;
}
