#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>>arr;

//위아래했을땐 좌우를 보고 좌우를 했을땐 위아래를 볼것
int N;

int check() {
	int result = 0;
	for (int i = 0; i < N; i++) {//상하체크
		int cnt = 1; char pre = 'M';
		for (int j = 0; j < N; j++) {
			if (pre != arr[i][j]) {
				pre = arr[i][j];
				result = max(result, cnt);
				cnt = 1;
			}
			else cnt++;
		}
		result = max(result, cnt);
	}
	for (int i = 0; i < N; i++) {//상하체크
		int cnt = 1; char pre = 'M';
		for (int j = 0; j < N; j++) {
			if (pre != arr[j][i]) {
				pre = arr[j][i];
				result = max(result, cnt);
				cnt = 1;
			}
			else cnt++;
		}
		result = max(result, cnt);
	}
	return result;
}

int main() {
	cin >> N;
	arr.resize(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int maxnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j - 1 < 0) continue;
			//좌우
			swap(arr[i][j - 1], arr[i][j]);
			maxnum = max(maxnum, check());
			swap(arr[i][j - 1], arr[i][j]);
			//상하
			swap(arr[j-1][i], arr[j][i]);
			maxnum = max(maxnum, check());
			swap(arr[j-1][i], arr[j][i]);
		}
	}
	cout << maxnum;
}