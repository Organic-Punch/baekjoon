#include <iostream>
#include <stack>

using namespace std;

int main() {
	string s, result; cin >> s;
	if (s.size() == 1) cout << 2;
	stack<char>st;
	bool ch[27] = { 0, };
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (st.empty()) { 
			st.push(s[i]); 
			ch[s[i] - '`'] = true; cnt++;
		}
		else if (!st.empty() && !ch[s[i] - '`']) {
			st.push(s[i]);
			ch[s[i] - '`'] = true; cnt++;
		}
	}
	return 0;
}