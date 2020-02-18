#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int testcase = 0;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		string s; int data;
		cin >> s;
		if (s == "push_back") {
			cin >> data;
			dq.push_back(data);
		}
		else if (s == "push_front") {
			cin >> data;
			dq.push_front(data);
		}
		else if (s == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (s == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if (s == "size") {
			cout << dq.size() << "\n";
		}
		else if (s == "empty") {
			if (!dq.empty())
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
		else if (s == "front") {
			if (!dq.empty())
				cout << dq.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (s == "back") {
			if (!dq.empty())
				cout << dq.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}
	return 0;
}