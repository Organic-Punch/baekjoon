#include <iostream>
#include <queue>
#include <tuple>
#pragma warning (disable : 4996)

using namespace std;

#define MAX 1002

int arr[MAX][MAX];
int check[MAX][MAX][2];
queue<tuple<int, int, int>>q;
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	q.push({ 0,0,1 });
	while (!q.empty()) {
		int cx = get<0>(q.front()), cy = get<1>(q.front()), block = get<2>(q.front());
		q.pop();
		if (cx == N - 1 && cy == M - 1) { cout << check[cx][cy][block] + 1; return 0; }
		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (arr[nx][ny] == 1 && block) {
					check[nx][ny][block - 1] = check[cx][cy][block] + 1;
					q.push({nx,ny,block-1});
				}
				else if (arr[nx][ny] == 0 && check[nx][ny][block] == 0) {
					check[nx][ny][block] = check[cx][cy][block] + 1;
					q.push({nx,ny,block});
				}
			}
		}
	}
	cout << -1;
	return 0;
}