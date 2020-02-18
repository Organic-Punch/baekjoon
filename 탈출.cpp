#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define pii pair<int,int>
int R, C, sx, sy, cnt;
vector<vector<char>>arr;
queue<pii>sq;
queue<pii>wq;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
pii endD;
int main() {
	cin >> R >> C;
	arr.resize(R, vector<char>(C, '?'));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') wq.push({ i,j });
			if (arr[i][j] == 'S') { sx = i; sy = j; sq.push({ i, j }); }
			if (arr[i][j] == 'D') endD = make_pair(i, j);
		}
	}
	bool ret = false;
	while (!wq.empty() || !sq.empty()) {
		cnt++;
		int csize = sq.size();
		for (int i = 0; i < csize; i++) {
			int cx = sq.front().first, cy = sq.front().second;
			sq.pop();
			if (arr[cx][cy] == '*')continue;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dir[i][0], ny = cy + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C || arr[nx][ny] == '*' || arr[nx][ny] == 'X') continue;
				if (arr[nx][ny] == '.') {
					sq.push({ nx,ny });
					arr[nx][ny] = 'S';
				}
				if (arr[nx][ny] == 'D') {
					sx = endD.first; sy = endD.second;
					ret = true;
					break;
				}
			}
		}
		if (sx == endD.first && sy == endD.second) break;
		csize = wq.size();
		for (int i = 0; i < csize; i++) {
			int cx = wq.front().first, cy = wq.front().second;
			wq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dir[i][0], ny = cy +dir[i][1];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C || arr[nx][ny] == 'D' || arr[nx][ny] == 'X') continue;
				if (arr[nx][ny] == '.' || arr[nx][ny] == 'S') {
					wq.push({ nx,ny });
					arr[nx][ny] = '*';
				}
			}
		}
	}
	if (ret) cout << cnt;
	else cout << "KAKTUS";
	return 0;
}