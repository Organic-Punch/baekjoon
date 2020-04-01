#include <cstdio>
int main() {
	int N, M, cnt = 0; scanf("%d", &N);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &M);
		if (M == N) cnt++;
	}
	printf("%d", cnt);
	return 0;
}