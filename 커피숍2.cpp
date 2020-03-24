#include <cstdio>
#include <cmath>
#include <algorithm>

#pragma warning (disable : 4996)
using namespace std;
#define llt long long int
llt seg[300000];
llt N, Q;
llt sz;
void update(int idx, llt val) {
	idx += sz;
	llt diff = val - seg[idx];
	seg[idx] = val;
	for (idx /= 2; idx > 0; idx /= 2) seg[idx] += diff;
}

long long int sum(llt itr, llt start, llt end, llt Left, llt Right) {
	if (Left <= start && end <= Right) return seg[itr];
	if (Right < start || Left > end) return 0;
	llt mid = (start + end) / 2;
	return sum(itr * 2, start, mid, Left, Right) + sum(itr * 2 + 1, mid + 1, end, Left, Right);
}

int main() {
	scanf("%d %d", &N, &Q);
	sz = pow(2, (llt)log2(N) + 1);
	for (int i = 0; i < N; i++) scanf("%lld",&seg[sz + i]);
	for (int i = sz - 1; i > 0; --i) seg[i] = seg[i * 2] + seg[i * 2 + 1];
	while (Q--) {
		llt x, y, a;llt b;
		scanf("%d %d %d %lld", &x, &y, &a, &b);
		if (x > y) { int temp = x; x = y; y = temp; }
		printf("%lld\n", sum(1, 1, sz, x, y));
		update(a - 1, b);
	}
	return 0;
}