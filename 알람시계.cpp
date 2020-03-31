#include <cstdio>
int main() {
	int H, M; scanf("%d %d", &H, &M);
	if (M < 45) {
		if (H != 0) printf("%d %d", H - 1, 15 + M);
		else printf("%d %d", 23, 15 + M);
	}
	else printf("%d %d", H, M-45);
	return 0;
}