#include <cstdio>
#include <cmath>
#include <algorithm>

#pragma warning (disable : 4996)
using namespace std;
#define llt long long int
llt seg[3000000];
int N, Q;
int size;
void insert(int idx, llt val) {
	idx += size;
	if (seg[idx] == 0) {
		seg[idx] += val;
		while (idx > 1) {
			idx /= 2;
			seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
		}
	}
	else {
		int diff = val - seg[idx];
		seg[idx] = val;
		for (idx /= 2; idx > 0; idx /= 2) {
			seg[idx] += diff;
		}
	}
}

long long int sum(int itr, int start, int end, int Left, int Right) {
	if (Left <= start && end <= Right) return seg[itr];
	if (Right < start || Left > end) return 0;
	int mid = (start + end) / 2;
	return sum(itr * 2, start, mid, Left, Right) + sum(itr * 2 + 1, mid + 1, end, Left, Right);
}

int main() {
	scanf("%d %d", &N, &Q);
	size = pow(2, (llt)log2(N) + 1);
	int a;
	while (Q--) {
		scanf("%d", &a);
		if (a == 1) {
			int b; llt c;
			scanf("%d %lld", &b, &c);
			insert(b-1,c);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			if (b > c) swap(b, c);
			printf("%lld\n", sum(1, 1, size, b, c));
		}
	}
	return 0;
}