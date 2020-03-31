#include <cstdio>
#pragma warning (disable : 4996)
int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int temp; scanf("%d", &temp);
		if (temp < M) printf("%d ", temp);
	}
	return 0;
}