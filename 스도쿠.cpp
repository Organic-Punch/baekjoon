#include <iostream>
#include <vector>

using namespace std;

#define pii pair<int,int>

vector<vector<int>>arr(9,vector<int>(9,0));
vector<pii>zero;

bool check(int value, int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (i == y) continue;
		if (value == arr[x][i]) return false;
	}
	for (int i = 0; i < 9; i++) {
		if (i == x) continue;
		if (value == arr[i][y]) return false;
	}
	int xidx = 0, yidx = 0;
	xidx = x < 3 ? 0 : x < 6 ? 3 : 6;
	yidx = y < 3 ? 0 : y < 6 ? 3 : 6;
	for (int i = xidx; i < xidx+3; i++) {
		for (int j = yidx; j < yidx + 3; j++) {
			if (i == x && y == j) continue;
			if (arr[i][j] == value) return false;
		}
	}
	return true;
}

void go(int idx) {
	if (idx >= zero.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	int x = zero[idx].first, y = zero[idx].second;
	int temp;
	for (int i = 1; i <= 9; i++) {
		if (check(i,x,y)) {
			temp = arr[x][y];
			arr[x][y] = i;
			go(idx + 1);
			arr[x][y] = temp;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				zero.push_back({ i,j });
			}
		}
	}
	go(0);
	return 0;
}