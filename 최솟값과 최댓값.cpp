#include <cstdio>
#include <cmath>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

#define llt long long int
#define plli pair<int,int>

plli seg[400000];
int N, M;
int cnt = 0, temp;
plli init(int itr, int start, int end) {
	if (cnt == N) return { 0, 0 };
	if (itr == temp && cnt++ < N) {
		temp++;
		scanf("%d", &seg[itr].first);
		seg[itr].second = seg[itr].first;
		return seg[itr];
	}
	int mid = (start + end) / 2;
	plli L = init(itr * 2, start, mid);
	plli R = init(itr * 2 + 1, mid + 1, end);
	if (L.first == 0 && R.first != 0)
		L.first = R.first;
	else if (L.first != 0 && R.first != 0)
		L.first = min(L.first, R.first);
	else if (L.first == R.first && R.first == 0)
		L.first = 0;

	if (L.second == 0 && R.second != 0)
		L.second = R.second;
	else if (L.second != 0 && R.second != 0)
		L.second = max(L.second, R.second);
	else if (L.second == R.second && R.second == 0)
		L.second = 0;
	return seg[itr] = L;
}

plli Find(int itr, int start, int end, int Left, int Right) {
	plli result = {0,0};
	//탈출조건
	if (Left <= start && end <= Right && seg[itr].first != 0 && seg[itr].second != 0) {
		result = { seg[itr].first,seg[itr].second };
		return result;
	}
	if (Right < start || Left > end) return { 0,0 };
	
	int mid = (start + end) / 2;
	
	plli L = Find(itr * 2, start, mid, Left, Right); 
	plli R = Find(itr * 2 + 1, mid + 1, end, Left, Right);
	
	if (L.first != 0 && R.first == 0) result.first = L.first;
	else if (R.first != 0 && L.first == 0) result.first = R.first;
	else if (L.first != 0 && R.first != 0) result.first = min(L.first, R.first);
	
	if (L.second != 0 && R.second == 0) result.second = L.second;
	else if (R.second != 0 && L.second == 0) result.second = R.second;
	else if (L.second != 0 && R.second != 0) result.second = max(L.second, R.second);

	return result;
}

int main() {
	scanf("%d %d", &N, &M);
	int size = pow(2, (llt)log2(N) + 1);//리프노드 위치생성
	temp = size;
	init(1, 1, (size * 2 - 1));
	while (M--) {
		int a, b; scanf("%d %d", &a, &b);
		plli result = Find(1, 1, size, a, b);
		printf("%d %d\n", result.first, result.second);
	}
	return 0;
}