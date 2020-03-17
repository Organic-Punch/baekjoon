#include <cstdio>
char arr[21][21]; bool vis[26];
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }, N, M, maxmove;
void B(int y = 0, int x = 0, int move = 1) {
	if (y < 0 || x < 0 || y >= N || x >= M || vis[arr[y][x] - 'A']) return;
	maxmove = maxmove < move ? move : maxmove;
	for (int i = 0; i < 4; i++) {
		vis[arr[y][x] - 'A'] = true;
		B(y + dir[i][0], x + dir[i][1], move + 1);
		vis[arr[y][x] - 'A'] = false;
	}
	return;
}

int main() {
	scanf("%d %d\n", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { scanf("%c", &arr[i][j]); if (arr[i][j] == '\n') scanf("%c", &arr[i][j]); }
	B();
	printf("%d", maxmove);
	return 0;
}