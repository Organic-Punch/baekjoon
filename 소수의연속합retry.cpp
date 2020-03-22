#include <cstdio>
#include <vector>
using namespace std;
vector<int>arr;
void che(int N) {
	vector<bool>prime(N + 1, 0);
	prime[0] = prime[1] = true;
	for (int i = 2; i <= N; i++) if (!prime[i]) for (int j = i*i; j <= N; j+= i) if (!prime[j]) prime[j] = true;
	for (int i = 2; i <= N; i++) if (!prime[i]) arr.push_back(i);
}

int main() {
	int N, result = 0, L = 0, R = 0; long long int sum = 0;
	scanf("%d", &N); che(N);
	while (L < arr.size() && R < arr.size() && arr[L] <= N) {
		if (sum >= N) sum -= arr[L++];
		else sum += arr[R++];
		if (sum == N) result++;
	}
	printf("%d", result);
	return 0;
}
