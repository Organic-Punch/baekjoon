#include <cstdio>
#include <vector>
#pragma warning (disable : 4996)
using namespace std;

int N, S;

int main() {
	scanf("%d %d", &N, &S);
	vector<int>arr(N, 0);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	int L = 0, R = 0, result = 987654321;
	long long int sum = 0;
	while (1) {
		if (sum >= S) sum -= arr[L++];
		else if (R == N) {
			while (L != N) {
				if (sum >= S) result = result > (R - L) ? (R - L) : result;
				sum -= arr[L++];
			}
			break;
		}
		else { sum += arr[R++]; }
		if (sum >= S) result = result > (R - L) ? (R - L) : result;
	}
	if (result != 987654321) printf("%d", result);
	else printf("0");
	return 0;
}