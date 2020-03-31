#include <cstdio>
int main() {
	int N, mak = 0; scanf("%d", &N);
	while (N != 0) {
		if (N%2==1) mak++;
		N /= 2;
	}
	printf("%d", mak);
	return 0;
}