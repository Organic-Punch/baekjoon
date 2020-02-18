#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define tiii tuple<int,int,int>
int dir[6][3] = { {0,0,-1}, {0,0,1}, {0,-1,0}, {0,1,0}, {-1,0,0}, {1,0,0} };
int main() {
	while (1) {
		int H, N, M; cin >> H >> N >> M;
		if (H == 0 && N == 0 && M == 0) return 0;
		int EH = 0, EN = 0, EM = 0;
		int arr[31][31][31] = {0,};
		queue<tiii>q;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					char A; cin >> A;
					if (A == 'S') q.push({ i,j,k });
					else if(A == '#') arr[i][j][k] = -1;
					else if (A == 'E') { EH = i; EN = j; EM = k; }
				}
			}
		}
		while (!q.empty()) {
			int ch = get<0>(q.front()), cx = get<1>(q.front()), cy = get<2>(q.front());
			if (ch == EH && cx == EN && cy == EM) { cout << "Escaped in " << arr[ch][cx][cy] << " minute(s).\n"; break; }
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nh = ch + dir[i][0], nx = cx + dir[i][1], ny = cy + dir[i][2];
				if (nh < 0 || nx < 0 || ny < 0 || nh >= H || nx >= N || ny >= M || arr[nh][nx][ny] == -1 || arr[nh][nx][ny] != 0) continue;
				q.push({ nh,nx,ny });
				arr[nh][nx][ny] = arr[ch][cx][cy] + 1;
			}
		}
		if (arr[EH][EN][EM] == 0) cout << "Trapped!\n";
	}
	return 0;
}