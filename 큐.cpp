#include <iostream>
#include <queue>
using namespace std;
queue<int>Q;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		string a; int num;
		cin >> a;
		if (a == "push") {
			cin >> num; Q.push(num);
		}
		else if (a == "pop") {
			if (Q.empty()) cout << -1 << endl;
			else {
				cout << Q.front() << endl;
				Q.pop();
			}
		}
		else if (a == "size") {
			cout << Q.size() << endl;
		}
		else if (a == "empty") {
			if (Q.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (a == "front") {
			if (!Q.empty()) cout << Q.front() << endl;
			else cout << -1 << endl;
		}
		else if (a == "back") {
			if (!Q.empty()) cout << Q.back() << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}