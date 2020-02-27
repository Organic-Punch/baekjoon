#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N; cin >> N;
	string S; getline(cin, S);
	for (int i = 0; i < N; i++) {
		getline(cin, S);
		stack<char>St;
		bool flag = false;
		for (int i = 0; i < S.length(); i++) {
			if (S[i] == '(') St.push('(');
			else if (S[i] == ')') {
				if (!St.empty()) {
					if(St.top() == '(') St.pop();
					else { flag = true; break; }
				}
				else { flag = true; break; }
			}
		}
		if (flag == true || !St.empty()) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}