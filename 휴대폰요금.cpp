#include <cstdio>
#pragma warning (disable : 4996)
#define Y 30
#define M 60
#define payY 10
#define payM 15

int main() {
	int N, ysum = 0, msum = 0; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp; scanf("%d", &temp);
		ysum += (temp / Y + 1) * payY;
		msum += (temp / M + 1) * payM;
	}
	if (ysum > msum) printf("M %d", msum);
	else if (ysum == msum) printf("Y M %d", msum);
	else printf("Y %d", ysum);
	return 0;
}