#include <iostream>

using namespace std;

int arr[100001];
int N, M;

bool check(int mid) {
	int sum = mid, num = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] > mid) return false;
		if (sum - arr[i] < 0) {
			sum = mid;
			num++;
		}
		sum -= arr[i];
	}
	return M >= num;
}

int main() {
	int sum = 0, result = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int L = 1, R = sum;
	while (L <= R) {
		int mid = (L + R) / 2;
		if (check(mid)) {
			result = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}
	cout << result;
	return 0;
}