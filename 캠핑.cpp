#include <cstdio>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int l, p, v, i = 1;
	while (scanf("%d %d %d", &l, &p, &v)) {
		if (l == p && p == v && v == 0) break;
		//5,8,20
		//총 20일 중 8일이라는 날을 2번 소요 가능하고 그중 2*5를 사용가능
		//그리고 나머지 4일을 을 더 이용가능 그래서 14
		//만약 l이 3이였다면 3일만 이용가능하기때문에 l과 v%p둘중 더 낮은 값 더하기
		printf("Case %d: %d\n", i++, ((v / p) * l + min(l, v % p)));
	}
	return 0;
}