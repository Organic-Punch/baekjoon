#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int>arr(N + 1, 0);
	vector<int>DP(N + 1, 0);
	for (int i = 1; i <= N; i++) cin >> arr[i];
	DP[1] = arr[1];
	DP[2] = arr[1] + arr[2];
	for (int i = 3; i <= N; i++) 
		DP[i] = max(DP[i - 1], max(DP[i-2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]));
	cout << DP[N];
	return 0;
}