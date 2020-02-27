#include<iostream>
#include<vector>

using namespace std;

#define llt long long int

int main() {
	int N, M; cin >> N >> M;
	vector<llt>arr(N);
	llt max = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max = arr[i] > max ? arr[i] : max;
	}
	llt L = 1, R = max * M, result = max * M;
	while (L <= R) {
		llt mid = (L + R) / 2;
		llt temp = 0;
		for (int i = 0; i < N; i++) temp += mid / arr[i];
		if (temp < M) {
			L = mid + 1;
		}
		else {
			if (result > mid) result = mid;
			R = mid - 1;
		}
	}
	cout << result;
	return 0;
}