#include <cstdio>
#pragma warning (disable : 4996)
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int M, D, sum = 0; scanf("%d %d", &M, &D);
	for (int i = 0; i < M; i++) 
		sum += month[i];
	sum += D;
	if (sum % 7 == 0) printf("SUN");
	else if (sum % 7 == 1) printf("MON");
	else if (sum % 7 == 2) printf("TUE");
	else if (sum % 7 == 3) printf("WED");
	else if (sum % 7 == 4) printf("THU");
	else if (sum % 7 == 5) printf("FRI");
	else if (sum % 7 == 6) printf("SAT");
	return 0;
}