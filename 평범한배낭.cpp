#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K, t1, t2;; cin >> N >> K;
	vector<int>arr(K+1, 0);
	for (int i = 0; i < N; i++) {
		cin >> t1 >> t2;
		for (int i = K; i > 0; i--) {
			if (t1 <= i) arr[i] = max(arr[i], arr[i - t1] + t2); else break;
		}
	}
	cout << arr[K];
	return 0;
}