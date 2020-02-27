#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, P, cnt = 0; cin >> N >> P;
	stack<int>ST[7];
	for (int i = 0; i < N; i++) {
		int jul, PNum; cin >> jul >> PNum;
		if (ST[jul].empty()) { ST[jul].push(PNum); cnt++; }
		else if (ST[jul].top() < PNum) { ST[jul].push(PNum); cnt++; }
		else if (ST[jul].top() > PNum) {
			while (!ST[jul].empty() && ST[jul].top() > PNum) {
				ST[jul].pop();
				cnt++;
			}
			if (!ST[jul].empty()) {
				if (ST[jul].top() != PNum) {
					ST[jul].push(PNum);
					cnt++;
				}
			}
			else {
				ST[jul].push(PNum);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}