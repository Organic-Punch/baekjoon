#include<iostream>
#include<cstdio>
using namespace std;
#pragma warning (disable : 4996)
int main(int argc, char** argv) {
	int test_case;
	int T, result = 0;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int num = 0; char E;
		while (1) {
			scanf("%d%c", &num, &E);
			if (num % 2 == 1) result += num;
			if (E == '\n') {
				printf("%d %d", test_case, result);
				result = 0;
				break;
			}
		}
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}