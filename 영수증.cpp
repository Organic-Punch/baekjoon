#include <cstdio>
int main() {
	int N, M; ; scanf("%d", &N);
	for (int i = 0; i < 9; i++) { scanf("%d", &M); N -= M; }
	printf("%d", N);
	return 0;
}