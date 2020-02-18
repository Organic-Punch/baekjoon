#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N;
vector<vector<int>>Ordinary_people;
vector<vector<int>>Disabled;
enum {UP = -1, DOWN =1, LEFT = -1, RIGHT = 1};
bool visited[101][101];
void DFS(int color, int i, int x = 0, int y = 0) {
	if (x < 0 || y < 0 || x >= N || y >= N || visited[x][y] == true) return;
	if (i == 0) {//일반인
		if (color != Ordinary_people[x][y]) return;
		visited[x][y] = true;
		DFS(color, i, x+UP, y);
		DFS(color, i, x+DOWN, y);
		DFS(color, i, x, y+LEFT);
		DFS(color, i, x, y+RIGHT);
	}
	else {//적록색약
		if (color != Disabled[x][y]) return;
		visited[x][y] = true;
		DFS(color, i, x + UP, y);
		DFS(color, i, x + DOWN, y);
		DFS(color, i, x, y + LEFT);
		DFS(color, i, x, y + RIGHT);
	}
}

int main() {
	cin >> N;
	Ordinary_people.resize(N, vector<int>(N, 0));
	Disabled.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp; cin >> temp;
			//R = 1, G = 2, B = 3
			if (temp == 'R') { Ordinary_people[i][j] = 1; Disabled[i][j] = 1; }
			else if (temp == 'G'){ Ordinary_people[i][j] = 2; Disabled[i][j] = 1; }
			else if (temp == 'B'){ Ordinary_people[i][j] = 3; Disabled[i][j] = 3; }
		}
	}
	vector<int>cnt(2, 0);
	int resultcnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < N; k++) {
			for (int r = 0; r < N; r++) {
				if (visited[k][r]) continue;
				resultcnt++;
				if (i == 0) DFS(Ordinary_people[k][r], i, k, r);
				else DFS(Disabled[k][r], i, k, r);
			}
		}
		cnt[i] = resultcnt;
		resultcnt = 0;
		memset(visited, 0, sizeof(visited));
	}
	cout << cnt[0] << ' ' << cnt[1];
	return 0;
}