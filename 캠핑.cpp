#include <cstdio>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int l, p, v, i = 1;
	while (scanf("%d %d %d", &l, &p, &v)) {
		if (l == p && p == v && v == 0) break;
		//5,8,20
		//�� 20�� �� 8���̶�� ���� 2�� �ҿ� �����ϰ� ���� 2*5�� ��밡��
		//�׸��� ������ 4���� �� �� �̿밡�� �׷��� 14
		//���� l�� 3�̿��ٸ� 3�ϸ� �̿밡���ϱ⶧���� l�� v%p���� �� ���� �� ���ϱ�
		printf("Case %d: %d\n", i++, ((v / p) * l + min(l, v % p)));
	}
	return 0;
}