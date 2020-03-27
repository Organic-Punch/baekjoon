#include <cstdio>
#pragma warning (disable : 4996)
using namespace std;
long long int arr[13];
long long int F(int n) {
	if ( n == 1) return 1;
	return n * F(n - 1);
}

int main() {
	int N; scanf("%d", &N);
	printf("%lld", F(N));
	return 0;
}