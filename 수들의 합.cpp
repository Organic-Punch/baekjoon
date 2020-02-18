#include <iostream>
#include <vector>
using namespace std;

int ret, sum, lowidx, highidx;

int main() {
	int N, M; cin >> N >> M;
	vector<int>arr(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	while (1) {
		if (sum >= M) sum -= arr[lowidx++];
		else if (highidx == N) break;
		else sum += arr[highidx++];
		if (sum == M)ret++;
	}
	cout << ret;
	return 0;
}