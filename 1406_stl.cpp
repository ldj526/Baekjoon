#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	list<char> L;

	for (auto a : s)
		L.push_back(a);
	auto cursor = L.end();
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		char c;
		cin >> c;
		switch (c) {
		case 'L':
			if (cursor != L.begin())
				cursor--;
			break;
		case 'D':
			if (cursor != L.end())
				cursor++;
			break;
		case 'B':
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
			break;
		case 'P':
			char d;
			cin >> d;
			L.insert(cursor, d);
			break;
		}
	}
	for (auto a : L)
		cout << a;
}
