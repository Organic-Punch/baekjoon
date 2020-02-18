#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define pii pair<int,int>
int dir[8][2] = { {-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1} };

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		int arr[301][301] = {0,};
		bool visited[301][301] = {0,};
		queue<pii>q;
		int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
		if (sx == ex && sy == ey) { cout << 0 << '\n'; continue; }
		q.push({ sx,sy });
		while (!q.empty()) {
			int cx = q.front().first, cy = q.front().second;
			q.pop();
			if (visited[cx][cy] == true) continue;
			visited[cx][cy] = true;
			if (arr[ex][ey]) { cout << arr[ex][ey] << '\n'; break; }
			for (int i = 0; i < 8; i++) {
				int nx = cx + dir[i][0], ny = cy + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] == true) continue;
				arr[nx][ny] = arr[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return 0;
}