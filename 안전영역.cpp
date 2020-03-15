//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <memory.h>
//
//using namespace std;
//#define pii pair<int,int>
//int N;
//enum {UP = -1, DOWN = 1, LEFT = -1, RIGHT = 1};
//vector<pii>high[101];
//vector<vector<int>>arr;
//bool vis[101][101];
//
//void DFS(int x,int y) {
//	if (x < 0 || y < 0 || x >= N || y >= N || arr[x][y] == 0 || vis[x][y] == 1) return;
//	vis[x][y] = 1;
//	DFS(x+UP, y);
//	DFS(x+DOWN, y);
//	DFS(x, y+LEFT);
//	DFS(x, y+RIGHT);
//}
//
//int main() {
//	cin >> N;
//	arr.resize(N, vector<int>(N, 0));
//	int maxnum = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> arr[i][j];
//			maxnum = arr[i][j] > maxnum ? arr[i][j] : maxnum;
//			high[arr[i][j]].push_back({i,j});
//		}
//	}
//	int result = 0;
//	int allcnt = 0;
//	int temp = arr[0][0];
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (temp != arr[i][j]) {
//				temp = -1;
//			}
//		}
//		if (temp == -1) break;
//	}
//	if (temp != -1) { cout << temp; return 0; }
//	for (int i = 1; i <= maxnum; i++) {
//		if (high[i].size() == 0) continue;
//		int cnt = 0;
//		memset(vis, 0, sizeof(vis));
//		for (int j = 0; j < high[i].size(); j++) {
//			arr[high[i][j].first][high[i][j].second] = 0;
//		}
//		for (int k = 0; k < N; k++) {
//			for (int r = 0; r < N; r++) {
//				if (vis[k][r] == 0 && arr[k][r] != 0) {
//					DFS(k, r);
//					cnt++;
//				}
//			}
//		}
//		result = result < cnt ? cnt : result;
//	}
//	cout << result;
//	return 0;
//}
#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int arr[101][101];
bool vis[101][101];
int N, H, result = 1;
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int DFS(int y, int x, int H) {
	if (y < 0 || y >= N || x < 0 || x >= N || arr[y][x] <= H || vis[y][x]) return 0;
	vis[y][x] = true;
	for (int i = 0; i < 4; i++) 
		DFS(y + dir[i][0], x + dir[i][1], H);
	return 1;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) { 
			scanf("%d", &arr[i][j]);
			H = H < arr[i][j] ? arr[i][j] : H;
		}
	if (H == 1) { printf("%d",result); return 0; }
	for (int h = 1; h <= H; h++) {
		int temp = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(arr[i][j] > h && !vis[i][j]) temp += DFS(i, j, h);
			}
		}
		result = max(result, temp);
	}
	printf("%d", result);
	return 0;
}