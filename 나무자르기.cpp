//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(void) {
//
//	long long M, N;
//	long long max = 0;
//	long long left, right;
//	long long result = 0;
//	cin >> N >> M;
//	vector<long long int>arr(N,0);
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//	sort(arr.begin(), arr.end());
//	max = arr[N - 1];
//	left = 0; right = max;
//	while (left <= right) {
//		long long mid = (left + right) / 2;
//		long long total = 0;
//		for (int i = 0; i < N; i++) if (mid < arr[i]) total += arr[i] - mid;
//		if (total >= M) {
//			if (result < mid) result = mid;
//			left = mid + 1;
//		}
//		else right = mid - 1;
//	}
//	cout << result;
//	return 0;
//}
#include <iostream>
#include <algorithm>

using namespace std;
long long int arr[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long int N, M, result = 0, left = 0, right, max = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	right = max;
	while (left <= right) {
		long long int mid = (left + right) / 2;
		long long int temp = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > mid)
				temp += arr[i] - mid;
		}
		if (temp >= M) {
			if (result < mid) {
				result = mid;	
			}
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << result;
	return 0;
}