#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	string S; getline(cin, S);
	for (int i = 0; i < N; i++) {
		getline(cin, S);
		stack<char>Cursor;
		stack<char>passward;
		for (int i = 0; i < S.length(); i++) {
			if (S[i] == '<') {
				if (!passward.empty()) {
					Cursor.push(passward.top());
					passward.pop();
				}
			}
			else if (S[i] == '>') {
				if (!Cursor.empty()) {
					passward.push(Cursor.top());
					Cursor.pop();
				}
			}
			else if (S[i] == '-') {
				if (!passward.empty()) {
					passward.pop();
				}
			}
			else passward.push(S[i]);
		}
		string ans;
		while (!Cursor.empty()) {
			passward.push(Cursor.top());
			Cursor.pop();
		}
		while (!passward.empty()) {
			ans += passward.top();
			passward.pop();
		}
		int sz = ans.length()-1;
		for (int i = sz; i >= 0; i--) cout << ans[i];
		cout << '\n';
	}
	return 0;
}