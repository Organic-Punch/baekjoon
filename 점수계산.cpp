#include <cstdio>
int main() {
	int N, cnt = 0, result = 0, temp = 0; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		
		scanf("%d", &temp);
		if (temp == 1) result += ++cnt;
		else if (temp == 0 && cnt != 0) cnt = 0;
	}
	printf("%d", result);
	return 0;
}