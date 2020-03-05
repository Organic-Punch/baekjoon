//32768 내소스
#include <iostream>

using namespace std;

int N, r, c, sz, cnt;

void B(int sx = 0, int sy = 0, int ex = sz-1, int ey = sz-1) {
	if (sx < 0 || sy < 0 || ex < sx || ey < sy) return;
	if(sx != ex || sy != ey){
		int midx = (sx + ex) / 2;
		int midy = (sy + ey) / 2;
		B(sx, sy, midx, midy);//좌상
		B(sx, midy + 1, midx, ey);//우상
		B(midx + 1, sy, ex, midy);//좌하
		B(midx + 1, midy + 1, ex, ey);//우하
	}
	else if (sx == ex && sy == ey) { 
		if (sx == r && sy == c) {  cout << cnt; exit(0); }
		cnt++;
		return;
	}
}

void dir() {
	sz = 1 << N;
	int midx = (0 + sz - 1) / 2, midy = (0 + sz - 1) / 2;
	cnt = (sz * sz) / 4;
	if (0 <= r && r <= midx && midy + 1 <= c && c <= sz - 1) {//우상 B(sx, midy + 1, midx, ey);
		B(0, midy + 1, midx, sz - 1);
	}
	else if (midx + 1 <= r && r <= sz - 1 && 0 <= c && c <= midy) {//좌하 B(midx + 1, sy, ex, midy);
		cnt *= 2;
		B(midx + 1, 0, sz - 1, midy);
	}
	else if (midx + 1 <= r && r <= sz - 1 && midy + 1 <= c && c <= sz - 1) {//우하 B(midx + 1, midy + 1, ex, ey);
		cnt *= 3;
		B(midx + 1, midy + 1, sz - 1, sz - 1);
	}
	else {//좌상 B(sx, sy, midx, midy);
		cnt = 0;
		B(0, 0, midx, midy);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> r >> c;
	dir();
	return 0;
}
//1등소스
//#include <stdio.h>
//int a, b, c, d, e = 1; 
//int main() { 
//	scanf("%d%d%d", &a, &b, &c); 
//	for (; a--;) { 
//		d += (c % 2) * e; c /= 2; e *= 2; 
//		d += (b % 2) * e; b /= 2; e *= 2; 
//	}
//	printf("%d", d); 
//}