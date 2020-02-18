#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int N, cnt = 0; cin >> N;
	vector<int>arr(N, 0);
	vector<int>between;

	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N-1; i++) between.push_back((arr[i+1] - arr[i]));
	int minnum = 987654321;

	for (int i = 0; i < between.size()-1; i++) {
		int temp = gcd(between[i], between[i+1]);
		minnum = minnum > temp ? temp : minnum;
	}
	for (int i = 0; i < N; i++) {
		if (i + 1 == N) break;
		if (arr[i + 1] - arr[i] != minnum) {
			int temp = (arr[i + 1] - arr[i]) / minnum - 1;
			cnt += temp;
		}
	}
	cout << cnt;
	return 0;
}