#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, ret = 0; cin >> N;
	string temp; getline(cin, temp);
	for (int i = 0; i < N; i++) {
		getline(cin, temp);
		stack<char>St;
		for (int i = 0; i < temp.length(); i++) {
			if (St.empty()) St.push(temp[i]);
			else if (temp[i] == 'A') {
				if (St.top() == 'A') St.pop();
				else St.push('A');
			}
			else if (temp[i] == 'B') {
				if (St.top() == 'B') St.pop();
				else St.push('B');
			}
		}
		if (St.empty()) ret++;
	}
	cout << ret;
	return 0;
}