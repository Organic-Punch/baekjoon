#include <iostream>
#include <vector>

using namespace std;
int N, M, K;
vector<vector<int>>arr;
bool visited[101][101];
enum {UP=-1,DOWN=1,LEFT=-1,RIGHT=1};
int DFS(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M || arr[x][y] == 0 || visited[x][y] == true) return 0;
	int temp = 1; visited[x][y] = true;
	temp += DFS(x+UP,y);
	temp += DFS(x+DOWN,y);
	temp += DFS(x,y+LEFT);
	temp += DFS(x,y+RIGHT);
	return temp;
}
int main() {
	cin >> N >> M >> K;
	arr.resize(N, vector<int>(M, 0));
	for (int i = 0; i < K; i++) {
		int x, y; cin >> x >> y;
		arr[x - 1][y - 1] = 1;
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				int temp = DFS(i, j);
				result = temp > result ? temp : result;
			}
		}
	}
	cout << result;
	return 0;
}