#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int arr[27] = {0,};
		int N, cnt = 0; cin >> N;
		for (int i = 0; i < N; i++) {
			string s; cin >> s;
			arr[s[0] - 64]++;
		}
		for (int i = 1; i < 27; i++) {
			if (arr[i] != 0) cnt++;
			else break;
		}
		cout <<'#' << i+1 << ' ' << cnt << '\n';
	}
	return 0;
}