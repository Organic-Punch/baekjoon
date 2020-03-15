#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define llt long long int
#define plli pair<llt,int>

plli seg[400000];
int N, K, Q, Max;
int cnt = 0, temp;
plli init(int itr, int start, int end) {
	if (cnt == N) return { 0, 0};
	if (itr == temp && cnt++ < N) {
		temp++;
		cin >> seg[itr].first;
		seg[itr].second = seg[itr].first;
		return seg[itr];
	}
	int mid = (start + end) / 2;
	plli L = init(itr * 2, start, mid);
	plli R = init(itr * 2+1, mid+1, end);
	L.first += R.first;
	L.second = max(L.second, R.second);
	return seg[itr] = L;
}

int sum(int itr, int start, int end, int Left, int Right) {
	//Ż������
	if (Left <= start && end <= Right) { Max = max(Max, seg[itr].second); return seg[itr].first; }
	if (Right < start || Left > end) return 0;
	//�̵尪
	int mid = (start + end) / 2;
	return sum(itr * 2, start, mid, Left, Right) + sum(itr * 2 + 1, mid + 1, end, Left, Right);
}

int main() {
	cin >> N >> K >> Q;
	int size = pow(2, (llt)log2(N) + 1);//������� ��ġ����
	temp = size;
	init(1, 1, (size * 2 - 1));
	//for (int i = 0; i < N; i++) {//������忡 ������ �� �Է�
	//	cin >> seg[size + i].first;
	//	seg[size + i].second = seg[size + i].first;
	//}
	//for (int i = size - 1; i > 0; --i) {//������� �� ���ϱ�
	//	seg[i].first = seg[i * 2].first + seg[i * 2 + 1].first;
	//	seg[i].second = max(seg[i * 2].second, seg[i * 2 + 1].second);
	//}
	while (Q--) {
		int a, b; cin >> a >> b; Max = 0;
		int sum1 = sum(1, 1, size, a, b);
		int len = b - a + 1;
		llt Maxnum = len * Max;
		Maxnum -= sum1;
		int temp = 0;
		temp = Maxnum / K;
		if (Maxnum % K != 0) temp += 1;
		cout << temp << '\n';
	}
	return 0;
}