#include <cstdio>
int main() {
	int N;
	scanf("%d", &N);
	N = 1000 - N;
	int coin = 500, cnt = 0; 
	for (int i = 0; i < 6; i++) { 
		coin = i == 1 ? 100 : i == 2 ? 50 : i == 3 ? 10 : i == 4 ? 5 : i == 5 ? 1 : coin; 
		cnt += N / coin; 
		if (N % coin == 0) { 
			printf("%d", cnt); 
			return 0; 
		}
		N -= (N / coin) * coin; 
	}
}