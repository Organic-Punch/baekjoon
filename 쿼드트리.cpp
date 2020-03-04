#include <iostream>
#include <vector>
#pragma warning (disable : 4996)

using namespace std;

vector<vector<int>>arr;
int N;
void C(int sx = 0, int sy = 0, int ex = N - 1, int ey = N - 1) {
	if (sx < 0 || sy < 0 || sx > ex || sy > ey) return;
	int midx = (sx + ex) / 2;
	int midy = (sy + ey) / 2;
	int a = arr[sx][sy];
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			if (a != arr[i][j]) goto EXIT;
		}
	}
	cout << arr[sx][sy];
	return;
EXIT:
	cout << '(';
	C(sx, sy, midx, midy);//ÁÂ»ó
	C(sx, midy + 1, midx, ey);//¿ì»ó
	C(midx + 1, sy, ex, midy);//ÁÂÇÏ
	C(midx + 1, midy + 1, ex, ey);//¿ìÇÏ
	cout << ')';
}

int main() {
	cin >> N;
	arr.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	C();
}