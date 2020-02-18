#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#pragma warning (disable : 4996)
using namespace std;
#define tiii tuple<int,int,int>
bool visited[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>>arr(N, vector<int>(M, 0));
	queue<tiii>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	q.push(make_tuple(0,0,1));
	while (!q.empty()) {
		int cx = get<0>(q.front()), cy = get<1>(q.front()), cnt = get<2>(q.front());
		q.pop();
		if (cx == N-1 && cy == M-1) { cout << cnt; return 0; }
		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 0 || visited[nx][ny] == true) continue;
			q.push(make_tuple(nx, ny, cnt+1));
			visited[nx][ny] = 1;
		}
	}
	return 0;
}