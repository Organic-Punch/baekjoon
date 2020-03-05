//32768 ���ҽ�
#include <iostream>

using namespace std;

int N, r, c, sz, cnt;

void B(int sx = 0, int sy = 0, int ex = sz-1, int ey = sz-1) {
	if (sx < 0 || sy < 0 || ex < sx || ey < sy) return;
	if(sx != ex || sy != ey){
		int midx = (sx + ex) / 2;
		int midy = (sy + ey) / 2;
		B(sx, sy, midx, midy);//�»�
		B(sx, midy + 1, midx, ey);//���
		B(midx + 1, sy, ex, midy);//����
		B(midx + 1, midy + 1, ex, ey);//����
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
	if (0 <= r && r <= midx && midy + 1 <= c && c <= sz - 1) {//��� B(sx, midy + 1, midx, ey);
		B(0, midy + 1, midx, sz - 1);
	}
	else if (midx + 1 <= r && r <= sz - 1 && 0 <= c && c <= midy) {//���� B(midx + 1, sy, ex, midy);
		cnt *= 2;
		B(midx + 1, 0, sz - 1, midy);
	}
	else if (midx + 1 <= r && r <= sz - 1 && midy + 1 <= c && c <= sz - 1) {//���� B(midx + 1, midy + 1, ex, ey);
		cnt *= 3;
		B(midx + 1, midy + 1, sz - 1, sz - 1);
	}
	else {//�»� B(sx, sy, midx, midy);
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
//1��ҽ�
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