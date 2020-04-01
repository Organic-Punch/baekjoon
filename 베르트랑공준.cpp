#include <cstdio>
#define MAX 246913
bool prime[MAX];
void che() {
	prime[0] = prime[1] = 1;
	for (int i = 2; i*i < MAX; i++) {
		if (!prime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				if (!prime[j]) prime[j] = true;
			}
		}
	}
}

int main() {
	che(); int n;
	while (scanf("%d",&n)) {
		if (n == 0) break;
		int cnt = 0;
		for (int i = n+1; i <= 2*n; i++) {
			if (!prime[i]) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}