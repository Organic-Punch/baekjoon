#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>arr;
int N, M;

void B(int idx, vector<int>s) {
	if (s.size() == M) {
		for (int i = 0; i < s.size(); i++) cout << s[i] << ' ';
		cout << '\n';
		return;
	}
	else {
		for (int i = idx; i < N; i++) {
			if (s.size() == 0) {
				s.push_back(arr[i]);
				B(i + 1, s);
				s.pop_back();
			}
			else {
				bool ch = false;
				for (int j = 0; j < s.size(); j++) {
					if (arr[i] == s[j]) { ch = true; break; }
				}
				if (!ch) {
					s.push_back(arr[i]);
					B(i + 1, s);
					s.pop_back();
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) { int x; cin >> x; arr.push_back(x); }
	sort(arr.begin(), arr.end());
	vector<int>s;
	B(0, s);
	return 0;
}