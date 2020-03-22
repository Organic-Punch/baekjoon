#include <cstdio>
int N, arr[10001], sum;
int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	int L = 0, R = 0, result = 0;
	while (1) {
		if (sum >= M) sum -= arr[L++];
		else if (R == N) break;
		else sum += arr[R++];
		if (sum == M) result++;
	}
	printf("%ld", result);
	return 0;
}