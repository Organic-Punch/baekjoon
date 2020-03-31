#include <cstdio>
int main() {
	int result = 0, A, B, sum = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &A, &B);
		sum += (B - A);
		result = result < sum ? sum : result;
	}
	printf("%d", result);
	return 0;
}
