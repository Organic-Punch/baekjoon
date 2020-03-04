#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int N; cin >> N;
		vector<vector<vector<int>>>arr(2,vector<vector<int>>(2,vector<int>(N+1,0)));
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j < N + 1; j++) {
				cin >> arr[0][i][j];
			}
		}
		arr[1][0][1] = arr[0][0][1];
		arr[1][1][1] = arr[0][1][1];
		for (int k = 2; k < N+1; k++) {
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					arr[1][0][k] = max(arr[1][1][k - 1], arr[1][1][k - 2]) + arr[0][0][k];
				}
				else {
					arr[1][1][k] = max(arr[1][0][k - 1], arr[1][0][k - 2]) + arr[0][1][k];
				}
			}
		}
		cout << max(arr[1][0][N], arr[1][1][N]) << '\n';
	}
	return 0;
}