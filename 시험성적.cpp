#include <cstdio>
int main() {
	int N; char result; scanf("%d", &N);
	result = N > 89 ? 'A' : N > 79 ? 'B' : N > 69 ? 'C' : N > 59 ? 'D' : 'F';
	printf("%c", result);
	return 0;
}