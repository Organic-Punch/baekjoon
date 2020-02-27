#include <iostream>
#include <stack>

using namespace std;

int main() {
	string S; cin >> S;
	stack<char>St;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/' || S[i] == '(') {
			St.push(S[i]);
		}
		else if (S[i] == ')') {
			while (!St.empty()) {
				if (St.top() == '(') {
					St.pop();
					break;
				}
				else {
					cout << St.top();
					St.pop();
				}
			}
		}
		else cout << S[i];
	}
	while (!St.empty()) {
		cout << St.top();
		St.pop();
	}
	return 0;
}