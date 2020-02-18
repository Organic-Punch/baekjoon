#include <iostream>
#include <vector>

using namespace std;
vector<int>dp;

int DP(int n) {
	if (n < 0)return 0;
	if (n <= 1)return 1;
	if (dp[n])return dp[n];
	return dp[n] = DP(n - 3) + DP(n - 2) + DP(n - 1);
}

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int n; cin >> n;
		dp.resize(n+1, 0);
		cout << DP(n) << '\n';
	}
}
//https://ssu-gongdoli.tistory.com/36