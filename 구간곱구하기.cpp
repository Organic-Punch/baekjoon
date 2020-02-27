#include <iostream>
#include <cmath>

using namespace std;
#define llt long long int
llt seg[1 << 21];
int N, n1, n2;

const llt MOD = 1e9 + 7;

llt mul(int itr, int start, int end, int Left, int Right) {
	//Ż������
	if (Left <= start && end <= Right) return seg[itr];
	if (Right < start || Left > end) return 1;
	//�̵尪
	int mid = (start + end) / 2;
	return (mul(itr * 2, start, mid, Left, Right) * mul(itr * 2 + 1, mid + 1, end, Left, Right))%MOD;
}

int main() {
	cin >> N >> n1 >> n2;
	int size = pow(2, (int)log2(N) + 1);//������� ��ġ����
	for (int i = size + N; i < (size*2); i++) {
		seg[i] = 1;
	}
	for (int i = 0; i < N; i++) {//������忡 ������ �� �Է�
		cin >> seg[size + i];
	}
	for (int i = size - 1; i > 0; --i) {//������� �� ���ϱ�
		seg[i] = (seg[i * 2] * seg[i * 2 + 1])% MOD;
	}
	int a, b, c;
	for (int i = 0; i < n1 + n2; i++) {
		cin >> a >> b >> c;
		if (a == 1) {//���� ����
			int itr = (size + b - 1);
			seg[itr] = c;
			for (itr /= 2; itr > 0; itr /= 2) seg[itr] = (seg[itr * 2] * seg[itr * 2 + 1]) % MOD;
		}
		else {//�ش� ���� ����Ҷ�
			cout << mul(1, 1, size, b, c) << '\n';
		}
	}
	return 0;
}