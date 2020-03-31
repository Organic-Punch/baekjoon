#include <cstdio>
int result = 987654321;
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i*5 <= N; i++) {
		int cnt = 0;
		cnt += i;
		if (((N - (i * 5)) % 3) == 0)
			cnt += ((N - (i * 5)) / 3);
		else continue;
		result = result > cnt ? cnt : result;
	}
	if (result == 987654321) printf("-1");
	else printf("%d", result);
	return 0;
}