#include <iostream>
#include <vector>

using namespace std;
//char arr[27][27];
vector<vector<char>>arr;

void C(int x, int y, int N) {
	if (N == 1) { arr[x][y] = '*'; return; }
	int div = N / 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) continue;
			C(x + (div * i), y + (div * j), div);
		}
	}
	return;
}

int main() {
	int N; cin >> N;
	arr.resize(N, vector<char>(N, ' '));
	C(0,0,N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << arr[i][j];
		cout << '\n';
	}
	return 0;
}