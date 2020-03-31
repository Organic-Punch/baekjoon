#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define llt long long int
int seg[400001], N, M, cnt = 0, temp;
int init(int itr, int start, int end) {
	if (cnt == N) return 0;
	if (itr == temp && cnt++ < N) {
		temp++;
		cin >> seg[itr];
		return seg[itr];
	}
	int mid = (start + end) / 2;
	int L = init(itr * 2, start, mid);
	int R = init(itr * 2 + 1, mid + 1, end);
	if (L == 0 && R != 0) return seg[itr] = R;
	else if (L != 0 && R == 0) return seg[itr] = L;
	else return seg[itr] = min(L,R);
}

int sum(int itr, int start, int end, int Left, int Right) {
	//탈출조건
	if (Left <= start && end <= Right) return seg[itr];
	if (Right < start || Left > end) return 0;
	//미드값
	int mid = (start + end) / 2;
	int L = sum(itr * 2, start, mid, Left, Right);
	int R = sum(itr * 2 + 1, mid + 1, end, Left, Right);
	if (L == 0 && R != 0) return R;
	else if (L != 0 && R == 0) return L;
	else return min(L, R);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int size = pow(2, (llt)log2(N) + 1);//리프노드 위치생성
	temp = size;
	init(1, 1, (size * 2 - 1));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum(1, 1, size, a, b) << '\n';
	}
	return 0;
}