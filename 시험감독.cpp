#include <cstdio>
#pragma warning (disable : 4996)
using namespace std;
int arr[1000001];
int main() {
	int num; scanf("%d", &num);
	for (int i = 0; i < num; i++) scanf("%d", &arr[i]);
	int B, C; scanf("%d %d", &B, &C);
	int cnt = 0;
	for (int i = 0; i < num; i++) {
		arr[i] -= B;
		cnt++;
		if (arr[i] > 0)
			cnt += (arr[i] % C == 0) ? (arr[i] / C) : (arr[i] / C + 1);
	}
	printf("%d", cnt);
	return 0;
}