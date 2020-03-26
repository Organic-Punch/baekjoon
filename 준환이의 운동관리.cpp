#include <cstdio>
#pragma warning (disable : 4996)
int main() {
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int L, H, X; scanf("%d %d %d", &L, &H, &X);
		if (X < L) printf("#%d %d\n", i, L - X);
		else if (H < X) printf("#%d %d\n", i, -1);
		else printf("#%d %d\n", i, 0);
	}
	return 0;
}