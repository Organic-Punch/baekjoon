#include <iostream>
#include <vector>
using namespace std;

int ret, sum, lowidx, highidx;

int main() {
	int N, M; cin >> N >> M;
	vector<int>arr(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	while (1) {
		if (sum >= M) sum -= arr[lowidx++]; // sum이 M보다크다면 arr[lowidx]의 값을 빼고 lowidx++
		else if (highidx == N) break;//highidx 가 N이라면 종료
		else sum += arr[highidx++];//sum이 M보다 작다면 arr[high]의 값을 더하고 highidx++
		if (sum == M) ret++;//같다면 카운트++
	}
	cout << ret;
	return 0;
}