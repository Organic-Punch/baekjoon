#include <cstdio>
int main() {
	int N, temp, cnt = 0; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (temp == 1) cnt++;
	}
	if (N - cnt > cnt) printf("Junhee is not cute!");
	else printf("Junhee is cute!");
}