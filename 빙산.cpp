#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#pragma warning (disable : 4996)
using namespace std;
#define pii pair<int,int>
int N, M;
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

vector<vector<int>>arr;
vector<vector<bool>>vis;
queue<pii>bing;
queue<pii>broken;

inline int check_bing(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M || vis[x][y] || arr[x][y] == 0) return 0;
	vis[x][y] = true;
	bing.push({ x,y });
	for (int i = 0; i < 4; i++) {
		check_bing(x+dir[i][0],y+dir[i][1]);
	}
	return 1;
}

inline void trans() {
	while (!broken.empty()) {
		arr[broken.front().first][broken.front().second] = 0;
		broken.pop();
	}
}

inline void melt() {
	while (!bing.empty()) {
		int x = bing.front().first, y = bing.front().second, sum = arr[x][y];
		bing.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != 0) continue;
			if (arr[nx][ny] == 0) sum--;
		}
		if (sum <= 0) { arr[x][y] = -1; broken.push({ x,y }); }
		else arr[x][y] = sum;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	arr.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { scanf("%d", &arr[i][j]); if (arr[i][j] != 0) bing.push({i,j}); }
	int year = 0;
	while (1) {
		year++;
		vis.clear();
		vis.resize(N, vector<bool>(M, 0));
		melt();
		if (!broken.empty()) trans();
		bool notmelted = false; int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0) {
					notmelted = true;
					sum += check_bing(i,j);
				}
			}
		}
		if (!notmelted) { printf("0"); return 0; }
		else if (sum != 0 && sum != 1) { printf("%d", year); return 0; }
	}
}