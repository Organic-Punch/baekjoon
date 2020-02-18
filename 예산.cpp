#include <iostream>
#include <algorithm>

using namespace std;

#define lli long long int

lli arr[10001];

int main() {
	int N, max = 0, result = 0, L = 0, R; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max = arr[i] > max ? arr[i] : max;
	}
	int M; cin >> M; R = max;
	while (L <= R) {
		lli mid = (L + R) / 2;
		lli temp = 0;
		for (int i = 0; i < N; i++) {
			temp += arr[i] < mid ? arr[i] : mid;
		}
		if (temp <= M) {
			result = mid;
			L = mid + 1;
		}
		else R = mid - 1;
	}
	cout << result;
	return 0;
}