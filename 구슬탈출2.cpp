//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//const int MAX_TRY = 10;
//const int INF = 987654321;
////상하좌우
//const int dy[4] = { -1, 1, 0, 0 };
//const int dx[4] = { 0, 0, -1, 1 };
//
//int N, M;	//세로, 가로
//char MAP[10][10];
//#define pii pair<int,int>
//
//pii R, B, O;
//
//int solve(int cnt, pii r, pii b, int dir) {
//	if (cnt > MAX_TRY) {
//		return INF;
//	}
//
//	int ry = r.first;
//	int rx = r.second;
//	int by = b.first;
//	int bx = b.second;
//
//	int res = INF;
//	if (dir != -1) {
//		while (MAP[ry + dy[dir]][rx + dx[dir]] == '.') {
//			ry += dy[dir];
//			rx += dx[dir];
//			if (ry == O.first && rx == O.second) {
//				res = cnt;
//				break;
//			}
//		}
//		while (MAP[by + dy[dir]][bx + dx[dir]] == '.') {
//			by += dy[dir];
//			bx += dx[dir];
//			if (by == O.first && bx == O.second) {
//				return res = INF;
//			}
//		}
//		if (res != INF) return res;
//
//		//움직임이 없을때 return;
//		if (ry == r.first && rx == r.second && by == b.first && bx == b.second) return res = INF;
//
//		//겹쳤을 때
//		if (ry == by && rx == bx) {
//			if (dir == 0) {
//				if (r.first < b.first) by++;
//				else ry++;
//			}
//			else if (dir == 1) {
//				if (r.first > b.first) by--;
//				else ry--;
//			}
//			else if (dir == 2) {
//				if (r.second < b.second) bx++;
//				else rx++;
//			}
//			else if (dir == 3) {
//				if (r.second > b.second) bx--;
//				else rx--;
//			}
//		}
//	}
//
//	for (int i = 0; i < 4; i++) {
//		res = min(res, solve(cnt + 1, pii(ry, rx), pii(by, bx), i));
//	}
//
//	return res;
//}
//
//int main() {
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> MAP[i][j];
//			if (MAP[i][j] == 'R') {
//				MAP[i][j] = '.';
//				R.first = i; R.second = j;
//			}
//			else if (MAP[i][j] == 'B') {
//				MAP[i][j] = '.';
//				B.first = i; B.second = j;
//			}
//			else if (MAP[i][j] == 'O') {
//				MAP[i][j] = '.';
//				O.first = i; O.second = j;
//			}
//		}
//	}
//
//	int res = solve(0, R, B, -1);
//	cout << (res == INF ? -1 : res) << endl;
//
//	return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define limit_Try 10
#define INF 987654321
#define pii pair<int,int>

char arr[10][10];
int N, M, result = INF, DIR[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
pii R, B, O;
void BackT(vector<vector<bool>>vis, int cnt = 0, pii r = { R.first,R.second }, pii b = { B.first,B.second }, int dir = -1) {
	if (cnt > limit_Try) { cout << -1; exit(0); }
	int rx = r.first, ry = r.second, bx = b.first, by = b.second;
	if (dir != -1) {
		if (arr[rx][ry] != '.') return;
		bool Rch = false, Bch = false;
		while (1) {
			vis[rx][ry] = true;
			if (arr[rx+DIR[dir][0]][ry+DIR[dir][1]] != '.') break;
			rx += DIR[dir][0]; ry += DIR[dir][1];
			if (vis[rx][ry]) return;
			if (rx == O.first && ry == O.second) { Rch = true; break; }
		}
		while (1) {
			if (arr[bx + DIR[dir][0]][by + DIR[dir][1]] != '.') break;
			bx += DIR[dir][0]; by += DIR[dir][1];
			if (bx == O.first && by == O.second) { Bch = true; break; }
		}
		if (Rch && !Bch) { result = min(result, cnt); return; }
		if (Bch) { result = INF; return; }
	}
	for (int i = 0; i < 4; i++) {
		vis[rx][ry] = true;
		BackT(vis, cnt + 1, { rx,ry }, { bx,by }, i);
		vis[rx][ry] = false;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') { arr[i][j] = '.'; R.first = i; R.second = j; }
			else if (arr[i][j] == 'B') { arr[i][j] = '.'; B.first = i; B.second = j; }
			else if (arr[i][j] == 'O') { arr[i][j] = '.'; O.first = i; O.second = j; }
		}
	}
	vector<vector<bool>>vis(N, vector<bool>(M, 0));
	BackT(vis);
	if (result != INF) cout << result;
	else cout << -1;
	return 0;
}