#include <iostream>
#include <algorithm>

using namespace std;

int arr[200000], N, C;

bool possible(int mid) {
	int cnt = 1, prev = arr[0];
	for (int i = 0; i < N; i++) {
		if (arr[i] - prev >= mid) {
			cnt++;
			prev = arr[i];
		}
	}
	if (cnt >= C) return 1;
	else return 0;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int L = 1, R = arr[N - 1] - arr[0], result = 0;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (possible(mid)) {
			result = result > mid ? result : mid;
			L = mid + 1;
		}
		else R = mid - 1;
	}
	cout << result;
	return 0;
}