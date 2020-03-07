#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>>arr;
//int arr[9][9];
vector<int>cnt(3, 0);

void Ios() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

void C(int x, int y, int N,int ii, int jj) {
	if (N == 1) {
		cnt[arr[x][y] + 1]++;
		return;
	}
	else {
		if (ii == 0) ii = 1;
		if (jj == 0) jj = 1;
		for (int i = x; i < x + N; i++) {
			for (int j = y; j < y + N; j++) {
				if (arr[x][y] != arr[i][j]) goto EXIT;
			}
		}
		cnt[arr[x][y] + 1]++;
		return;
	}
EXIT:
	int div = N / 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			C(x + (div * i), y + (div * j), div,i,j);
		}
	}
	return;
}

int main() {
	Ios();
	int N; cin >> N;
	arr.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];
	C(0, 0, N,1,1);
	cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';
	return 0;
}