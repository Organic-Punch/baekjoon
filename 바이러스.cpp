#include <cstdio>
#include <queue>
#pragma warning (disable : 4996)
using namespace std;

#define pii pair<int,int>
int network[101][101], N, P, cnt;
bool vis[101];

void DFS(int x = 1) {
	if (x < 1 || x > N || vis[x]) return;
	vis[x] = true; cnt++;
	for (int i = 1; i <= N; i++) {
		if (network[x][i] == 1 && !vis[i]) DFS(i);
	}
}

int main() {
	scanf("%d %d", &N, &P);
	for (int i = 0; i < P; i++) {
		int x, y; scanf("%d %d", &x, &y);
		network[x][y] = 1;
		network[y][x] = 1;
	}
	DFS();
	printf("%d", cnt - 1);
	return 0;
}