#include <iostream>
#include <stack>

using namespace std;

string S;

int P(char T) {
	if (T == ')') return 3;
	else if (T == '*' || T == '/') return 2;
	else if (T == '+' || T == '-') return 1;
}

int main() {
	 cin >> S;
	stack<char>ST;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/' || S[i] == '(' || S[i] == ')') {
			if (S[i] == '(') ST.push(S[i]);
			else if (P(S[i]) == 3) {
				while (!ST.empty()) {
					if (ST.top() == '(') { ST.pop(); break; }
					else { cout << ST.top(); ST.pop(); }
				}
			}
			else if (P(S[i]) == 2) {
				while (!ST.empty()) {
					if (ST.top() != '(' && ST.top() != '+' && ST.top() != '-') { cout << ST.top(); ST.pop(); }
					else break;
				}
				ST.push(S[i]);
			}
			else if (P(S[i]) == 1) {
				while (!ST.empty()) {
					if (ST.top() != '(')
					{
						cout << ST.top(); ST.pop();
					}
					else break;
				}
				ST.push(S[i]);
			}
		}
		else cout << S[i];
	}
	while (!ST.empty()) {
		cout << ST.top(); ST.pop();
	}
	return 0;
}