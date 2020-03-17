#include <cstdio>
#include <memory.h>
#pragma warning (disable:4996)
int cnt[2], M[41];
int fi(int n) {
	if (n <= 1) { cnt[0]++; return M[n]; }
	else if (M[n] > 0) { cnt[1]++; return M[n]; }
	else return M[n] = fi(n - 1) + fi(n - 2);
}

int main() {
	int t, n; scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		if (n == 0) printf("1 0\n");
		else {
			if (i != 0) {
				cnt[0] = cnt[1] = 0;
				memset(M, 0, sizeof(M));
			}
			M[0] = M[1] = 1;
			printf("%d %d\n", fi(n-2), fi(n-1));
		}
	}
	return 0;
}