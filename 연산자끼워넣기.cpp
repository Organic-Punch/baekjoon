#include <cstdio>
int N, culcnt, Max = -1000000000, Min = 1000000000, arr[11], cul[4];
void B(int ret = arr[0], int culpos = 0, int pos = 1) {
	if (culpos == culcnt) {
		Max = Max < ret ? ret : Max;
		Min = Min > ret ? ret : Min;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (cul[i] != 0) {
			if (i == 0 && cul[i] != 0) { cul[i]--; B(ret + arr[pos], culpos + 1, pos + 1); cul[i]++; }
			else if (i == 1 && cul[i] != 0) { cul[i]--; B(ret - arr[pos], culpos + 1, pos + 1); cul[i]++; }
			else if (i == 2 && cul[i] != 0) { cul[i]--; B(ret * arr[pos], culpos + 1, pos + 1); cul[i]++; }
			else if (i == 3 && cul[i] != 0) { cul[i]--; B(ret / arr[pos], culpos + 1, pos + 1); cul[i]++; }
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 4; i++) { scanf("%d", &cul[i]); culcnt += cul[i]; }
	B();
	printf("%d\n%d", Max, Min);
	return 0;
}