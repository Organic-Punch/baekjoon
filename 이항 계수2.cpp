#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>arr(1002,vector<int>(1002,0));
int N, K;

int main() {
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0 || i == 1) arr[i][j] = 1;
			else if (arr[i][j] == 0) {
				arr[i][j] = ((arr[i - 1][j] + arr[i - 1][j - 1])%10007);
			}
		}
	}
	cout << arr[N][K];
	return 0;
}