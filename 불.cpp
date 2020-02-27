#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N, M;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N;
		vector<vector<int>>arr(N, vector<int>(M, 0));
		queue<pii>sq;
		queue<pii>fq;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				char temp; cin >> temp;
				if (temp == '#') arr[i][j] = -1;
				else if (temp == '*') {
					fq.push({ i,j });
					arr[i][j] = -2;
				}
				else if (temp == '@') {
					sq.push({ i,j });
					arr[i][j] = 1;
				}
			}
		}
		
		while (!sq.empty() || !fq.empty()) {
			int sz = fq.size();
			for (int i = 0; i < sz; i++) {
				int cx = fq.front().first, cy = fq.front().second;
				fq.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cx + dir[i][0], ny = cy + dir[i][1];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == -1 || arr[nx][ny] == -2) continue;
					arr[nx][ny] = -2;
				}
			}
			sz = sq.size();
			for (int i = 0; i < sz; i++) {
				int cx = sq.front().first, cy = sq.front().second;
				fq.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cx + dir[i][0], ny = cy + dir[i][1];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] != 0) continue;
					arr[nx][ny] = arr[cx][cy] + 1;
				}
			}
		}
	}
	return 0;
}