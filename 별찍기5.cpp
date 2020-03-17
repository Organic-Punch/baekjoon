#include <cstdio>
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N - i - 1; k++) printf(" ");
		for (int j = 0; j < i; j++) printf("*");
		printf("*");
		for (int j = 0; j < i; j++) printf("*");
		printf("\n");
	}
	return 0;
}