#include <iostream>

using namespace std;

#define lli long long int
#define MAX 10000

int N, M;
lli arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	lli R = 0, result = 0, L = 1;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		R = R > arr[i] ? R : arr[i];
	}
	while (L <= R) {
		lli mid = (L + R) / 2;
		int temp = 0;
		for (int i = 0; i < N; i++) {
			temp += arr[i] / mid;
		}
		if (temp >= M) {
			result = result < mid ? mid : result;
			L = mid + 1;
		}
		else R = mid - 1;
	}
	cout << result << "\n";
	return 0;
}