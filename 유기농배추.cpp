//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#define pii pair<int,int>
//
//vector<pii>pos;
//vector<vector<int>>arr;
//vector<vector<bool>>check;
//int N, M, K;
//int result;
//enum { UP = -1, DOWN = 1, LEFT = -1, RIGHT = 1 };
//
//int DFS(int x, int y) {
//	if (x < 0 || y < 0 || x >= N || y >= M || check[x][y] == true || arr[x][y] == 0) return 0;
//	check[x][y] = true;
//	DFS(x+UP,y);
//	DFS(x+DOWN,y);
//	DFS(x,y+LEFT);
//	DFS(x,y+RIGHT);
//	return 1;
//}
//
//int main() {
//	int T; cin >> T;
//	for (int i = 0; i < T; i++) {
//		cin >> N >> M >> K;
//		result = 0;
//		arr.clear(); check.clear(); pos.clear();
//		arr.resize(N, vector<int>(M, 0));
//		check.resize(N, vector<bool>(M, 0));
//		for (int i = 0; i < K; i++) {
//			int x, y; cin >> x >> y;
//			arr[x][y] = 1;
//			pos.push_back({ x,y });
//		}
//		for (int i = 0; i < K; i++) {
//			if (DFS(pos[i].first, pos[i].second) == 1) {
//				result += 1;
//			}
//		}
//		cout << result << '\n';
//	}
//	return 0;
//}
#include <iostream>
#include <vector>

using namespace std;

#define pii pair<int,int>

vector<vector<int>>arr;
vector<vector<bool>>vis;
vector<pii> pos;
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int N, M, K;

int DFS(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] == 0 || vis[x][y]) return 0;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) DFS(x + dir[i][0], y + dir[i][1]);
	return 1;
}

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M >> K;
		if (i != 0) { arr.clear(); vis.clear(); pos.clear(); }
		arr.resize(N, vector<int>(M, 0));
		vis.resize(N, vector<bool>(M, 0));
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			arr[x][y] = 1;
			pos.push_back({ x,y });
		}
		int result = 0;
		for (int i = 0; i < K; i++) {
			result += DFS(pos[i].first,pos[i].second);
		}
		cout << result << '\n';
	}
	return 0;
}