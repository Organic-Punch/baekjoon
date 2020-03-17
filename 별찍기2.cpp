#include <cstdio>
#pragma warning (disable : 4996)
int main() {
	int N; scanf("%d", &N);
	int S = N - 1;
	for (int i = 0; i < N; i++) {
		for (int i = 0; i < S; i++) printf(" "); S--;
		for (int j = 0; j < i + 1; j++) printf("*");
		printf("\n");
	}
	return 0;
}