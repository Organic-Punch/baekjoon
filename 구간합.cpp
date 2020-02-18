//#include <iostream>
//#include <cmath>
//
//using namespace std;
//#define llt long long int
//llt seg[1 << 21];
//
//int sum(int itr, int start, int end, int l, int r) {
//	if (l <= start && end <= r)return seg[itr];
//	if (r < start || end < l) return 0;
//	int mid = (start + end) / 2;
//	return sum(itr * 2, start, mid, l, r) + sum((itr * 2) + 1, mid + 1, end, l, r);
//}
//
//int main() {
//	int N, M, K;
//	cin >> N >> M >> K;
//	llt size = pow(2, (llt)log2(N) + 1);
//	for (int i = 0; i < N; i++) {
//		cin >> seg[size + i];
//	}
//	for (int i = size-1; i > 0; --i) {
//		seg[i] = seg[i * 2] + seg[i * 2 + 1];
//	}
//	int a, b, c;
//	for (int i = 0; i < M+K; i++) {
//		cin >> a >> b >> c;
//		if (a == 1) {
//			llt itr = size + b - 1;
//			llt diff = c - seg[itr];
//			seg[itr] = c;
//			for (itr /= 2; itr > 0; itr/=2) seg[itr] += diff;
//		}
//		else if (a == 2) {
//			cout << sum(1, 1, size, b, c) << '\n';
//		}
//	}
//	return 0;
//}

//구간 합 구하기 세그먼트 트리
#include <iostream>
#include <cmath>

using namespace std;
#define llt long long int
int seg[1 << 21];
int N, n1, n2;

int sum(int itr, int start, int end, int Left, int Right) {
	//탈출조건
	if (Left <= start && end <= Right) return seg[itr];
	if (Right < start || Left > end) return 0;
	//미드값
	int mid = (start + end) / 2;
	return sum(itr*2, start, mid, Left, Right) + sum(itr*2+1, mid + 1, end, Left, Right);
}

int main() {
	cin >> N >> n1 >> n2;
	int size = pow(2, (llt)log2(N) + 1);//리프노드 위치생성
	for (int i = 0; i < N; i++) {//리프노드에 데이터 값 입력
		cin >> seg[size + i];
	}
	for (int i = size-1; i > 0; --i) {//상위노드 값 구하기
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
	int a, b, c;
	for (int i = 0; i < n1 + n2; i++) {
		cin >> a >> b >> c;
		if (a == 1) {//값을 변경
			int itr = (size + b - 1);
			int diff = c - seg[itr];
			seg[itr] = c;
			for (itr /= 2; itr > 0; itr/=2) {
				seg[itr] += diff;
			}
		}
		else {//해당 값을 출력할때
			cout << sum(1, 1, size, b, c) << '\n';
		}
	}
	return 0;
}