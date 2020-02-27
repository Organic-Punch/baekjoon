#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	stack<char>result;
	stack<char>temp;
	string S; getline(cin, S);
	for (int i = 0; i < S.length(); i++) {
		result.push(S[i]);
	}
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char Q; cin >> Q;
		if (Q == 'L') {
			if (!result.empty()) {
				temp.push(result.top());
				result.pop();
			}
		}
		else if (Q == 'D') {
			if (!temp.empty()) {
				result.push(temp.top());
				temp.pop();
			}
		}
		else if (Q == 'B') {
			if (!result.empty()) {
				result.pop();
			}
		}
		else {
			char insert; cin >> insert;
			result.push(insert);
		}
	}
	while (!temp.empty()) {
		result.push(temp.top());
		temp.pop();
	}
	string ret;
	while (!result.empty()) {
		ret += result.top();
		result.pop();
	}
	int sz = ret.length()-1;
	for (int i = sz; i >= 0; i--)	{
		cout << ret[i];
	}
	return 0;
}