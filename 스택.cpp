#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int>ST;
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		string A; cin >> A;
		if (A == "push") {
			int x; cin >> x;
			ST.push(x);
		}
		else if (A == "pop") {
			if (!ST.empty()) {
				cout << ST.top() << "\n";
				ST.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (A == "size") {
			cout << ST.size() << "\n";
		}
		else if (A == "empty") {
			if (ST.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (A == "top") {
			if (ST.empty()) {
				cout << -1 << "\n";
			}
			else
				cout << ST.top() << "\n";
		}
	}
	return 0;
}