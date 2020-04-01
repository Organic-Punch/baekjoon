#include <cstdio>
bool arr[31];
int main() {
	for (int i = 0; i < 28; i++) {
		int temp; scanf("%d", &temp);
		arr[temp] = true;
	}
	for (int i = 1; i < 31; i++) if (!arr[i]) printf("%d\n", i);
	return 0;
}