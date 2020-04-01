#include <cstdio>
int main() {
	for (int i = 0; i < 3; i++) {
		int a = 0, b = 0, temp;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &temp);
			if (temp == 0) a++; else b++;
		}
		if (a == 0) printf("E\n");
		else if (a == 1) printf("A\n");
		else if (a == 2) printf("B\n");
		else if (a == 3) printf("C\n");
		else if (a == 4) printf("D\n");
	}
	return 0;
}