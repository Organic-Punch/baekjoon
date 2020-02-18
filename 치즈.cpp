#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;
int N, M;
int arr[101][101];
bool vis[101][101];
int lastcnt = 0;
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
#define pii pair<int,int>
bool allclear() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) cnt++;
		}
	}
	if (cnt != 0) lastcnt = cnt;
	return cnt == 0 ? true : false;
}

void BFSAIR() {
	memset(vis, 0, sizeof(vis));
	queue<pii>q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0];
			int ny = cy + dir[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (!vis[nx][ny] && (!arr[nx][ny] || arr[nx][ny] == 3)) {
					arr[nx][ny] = 3;
					q.push({ nx, ny });
					vis[nx][ny] = true;
				}
			}
		}
	}
}

void BFSDEL() {
	memset(vis, 0, sizeof(vis));
	queue<pii>q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0];
			int ny = cy + dir[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !vis[nx][ny]) {
				if (arr[nx][ny] == 3) {
					q.push({ nx, ny });
					vis[nx][ny] = true;
				}
				if (arr[cx][cy] == 3 && arr[nx][ny] == 1) {
					arr[nx][ny] = 2;
					q.push({ nx, ny });
					vis[nx][ny] = true;
				}
			}
		}
	}
}

void repair() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 2)
				arr[i][j] = 3;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int result = 0;
	while (1) {
		if (allclear()) break;
		result++;
		BFSAIR();
		BFSDEL();
		repair();
	}
	cout << result << '\n' << lastcnt;
	return 0;
}