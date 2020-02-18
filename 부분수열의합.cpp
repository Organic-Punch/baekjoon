#include <iostream>
#include <vector>

using namespace std;

int N, S, ret = 0;
vector<int>arr;

void check(int idx = 0, int sum = 0) {
	if (idx >= N) return;
	sum += arr[idx];
	if (sum == S) ret++;
	check(idx + 1, sum - arr[idx]);
	check(idx + 1, sum);
}

int main() {
	cin >> N >> S;
	arr.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	check();
	cout << ret;
	return 0;
}