#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define pii pair<int,int>
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>>arr(M, vector<int>(N, 0));
	queue<pii>q;
	for (int i = 0; i < M; i++) {		
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)q.push({ i,j });
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int cx = q.front().first, cy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dir[i][0], ny = cy + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= M || ny >= N || arr[nx][ny] == -1 || arr[nx][ny] == -1) continue;
				if (arr[nx][ny] == 0) {
					q.push({ nx,ny });
					arr[nx][ny] = 1;
				}
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt-1;
	return 0;
}