#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int>st;
	string s;
	int n, a;
	cin >> n;
	int temp = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a >= temp) {
			for (int i = temp; i <= a; i++) {
				st.push(i);
				s += "+";
			}
		}
		temp = temp > a + 1 ? temp : a + 1;
		for (int i = a; i >= 1; i--) {
			if (st.empty()) {
				cout << "NO";
				return 0;
			}
			if (st.top() == a) {
				st.pop();
				s += "-";
				break;
			}
			else {
				st.pop();
				s += "-";
			}
		}
	}
	for (int i = 0; i < s.length(); i++) {
		cout << s[i] << "\n";
	}

	return 0;
}