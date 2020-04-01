#include <cstdio>
#include <memory.h>
#pragma warning (disable : 4996)
char arr[5][16];
int main() {
	memset(arr, '.', sizeof(arr));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 16; j++) {
			char temp; scanf("%c", &temp);
			if (temp == '\n') break;
			arr[i][j] = temp;
		}
	}
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == '.') continue;
			printf("%c", arr[j][i]);
		}
	}
	return 0;
}