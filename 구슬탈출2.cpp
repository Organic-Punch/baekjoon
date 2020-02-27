#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int main() {
	int N, M; cin >> N >> M;
	vector<vector<char>>arr(N, vector<char>(M, '.'));
	queue<pii>Redq;
	queue<pii>Blueq;
	int goalx = 0, goaly = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') Redq.push({ i,j });
			else if (arr[i][j] == 'B') Blueq.push({ i,j });
			else if (arr[i][j] == '0'){ goalx = i; goaly = j; }
		}
	}
	while (!Redq.empty() && !Blueq.empty()) {
		int sz = Redq.size(); vector<int>go;
		for (int i = 0; i < sz; i++) {
			int cx = Redq.front().first, cy = Redq.front().second;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dir[i][0], ny = cy + dir[i][1];
				if (arr[nx][ny] == '.') {
					go.push_back(i);
					int a = nx, b = ny;
					while (1) {
						if (arr[a][b] != '.') arr[a][b] = 'R';
						
					}
				}
			}
		}

	}
	return 0;
}