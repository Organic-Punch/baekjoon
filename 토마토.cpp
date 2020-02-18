#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
int N, M, H;
queue<tuple<int, int, int>>q;
vector<vector<vector<int>>>arr;
int dir[6][3] = { {0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0} };
                   //상        하       좌        우        위       아래
int main() {
	cin >> M >> N >> H;
	arr.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) q.push({ i,j,k });
			}
		}
	}
	while (!q.empty()) {
		int ch = get<0>(q.front()), cn = get<1>(q.front()), cm = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nh = ch + dir[i][0], nn = cn + dir[i][1], nm = cm + dir[i][2];
			if (nh < 0 || nm < 0 || nn < 0 || nh >= H || nm >= M || nn >= N) continue;
			if (arr[nh][nn][nm] == 1) continue;
			if (arr[nh][nn][nm] == 0) {
				q.push({ nh,nn,nm });
				arr[nh][nn][nm] = arr[ch][cn][cm] + 1;
			}
		}
	}
	int day = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0) {
					cout << -1; return 0;
				}
				day = day < arr[i][j][k] ? arr[i][j][k] : day;
			}
		}
	}
	cout << day-1;
	return 0;
}