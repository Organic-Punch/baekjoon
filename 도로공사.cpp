#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define llt long long int
#define plli pair<llt,int>

plli seg[400000];
int N, M, Q, Max;
int cnt = 0, temp;
plli init(int itr, int start, int end) {
	if (cnt == N) return { 0, 0};
	if (itr == temp && cnt++ < N) {
		temp++;
		cin >> seg[itr].first;
		seg[itr].second = seg[itr].first;
		return seg[itr];
	}
	int mid = (start + end) / 2;
	plli L = init(itr * 2, start, mid);
	plli R = init(itr * 2+1, mid+1, end);
	L.first += R.first;
	L.second = max(L.second, R.second);
	return seg[itr] = L;
}

int find(int itr, int start, int end, int Left, int Right) {
	//탈출조건
	if (Left <= start && end <= Right) { Max = max(Max, seg[itr].second); return seg[itr].first; }
	if (Right < start || Left > end) return 0;
	//미드값
	int mid = (start + end) / 2;
	return find(itr * 2, start, mid, Left, Right) + find(itr * 2 + 1, mid + 1, end, Left, Right);
}

int main() {
	cin >> N >> M >> Q;
	int size = pow(2, (llt)log2(N) + 1);//리프노드 위치생성
	temp = size;
	init(1, 1, (size * 2 - 1));
	while (Q--) {
		int a, b; cin >> a >> b; Max = 0;
		int sum1 = find(1, 1, size, a, b);
		int len = b - a + 1;
		llt Maxnum = len * Max;
		Maxnum -= sum1;
		int temp = 0;
		temp = Maxnum / M;
		if (Maxnum % M != 0) temp += 1;
		cout << temp << '\n';
	}
	return 0;
}