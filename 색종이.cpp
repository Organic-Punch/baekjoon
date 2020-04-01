#include <cstdio>
#pragma warning (disable : 4996)
int arr[101][101];
//int C(int sx, int sy, int ex, int ey) {
//	if (sx < 0 || sx >= 101 || sy < 0 || ey >= 101) return 0;
//	if (sx == ex && sy == ey) {
//		if (arr[sx][sy] == 0) return 0;
//		else return 1;
//	}
//	int cnt = 0; bool check = false;
//	for (int i = sx; i <= ex; i++) {
//		for (int j = sy; j < ey; j++) {
//			if (arr[i][j] == 0) goto EXIT;
//			cnt++;
//		}
//	}
//	return cnt;
//EXIT:
//	int sum = 0;
//	int xmid = (sx + ex) / 2, ymid = (sy + ey) / 2;
//	sum += C(sx, sy, xmid, ymid);//ÁÂ»ó
//	sum += C(sx, ymid + 1, ymid, ey);//¿ì»ó
//	sum += C(xmid + 1, sy, ex, ymid);//ÁÂÇÏ
//	sum += C(xmid + 1, ymid + 1, ex, ey);//¿ìÇÏ
//	return sum;
//}
int main() {
	int N; scanf("%d", &N);
	bool check = false;
	for (int T = 0; T < N; T++) {
		int S, E; scanf("%d %d", &S, &E);
		for (int i = S; i < S+10; i++) {
			for (int j = E; j < E+10; j++) {
				if (arr[i][j] == 1) { check = true; continue; }
				else arr[i][j] = 1;
			}
		}
	}
	if (!check) printf("%d", N * 100);
	else {
		int result = 0;
		for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) if (arr[i][j] == 1) result++;
		printf("%d", result);
	}
	return 0;
}