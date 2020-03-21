#include <cstdio>
#pragma warning (disable : 4996)
int N, M, K, cnt, arr[5][5], dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
bool vis[5][5];

void B(int length = 1, int x = N-1, int y = 0) {
	if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] == -1 || vis[x][y]) return;
	if (x == 0 && y == M - 1) {
		if (length == K) {
			cnt++; return;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		vis[x][y] = true;
		arr[x][y] = length;
		B(length + 1, x + dir[i][0], y + dir[i][1]);	
	}
	arr[x][y] = 0;
	vis[x][y] = false;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp; scanf("%c", &temp);
			if (temp == '\n') scanf("%c", &temp);
			if (temp == 'T') arr[i][j] = -1;
		}
	}
	arr[N - 1][0] = 1;
	B();
	printf("%d", cnt);
	return 0;
}