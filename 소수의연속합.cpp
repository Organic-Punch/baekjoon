#include <iostream>
#include <vector>

using namespace std;

#define max 4000001

bool prime[max];
vector<int>P;
void E() {
	prime[1] = prime[0] = true;
	for (int i = 2; i*i < max; i++) {
		if (!prime[i]) 
			for (int j = i * i; j < max; j += i) 
				if (!prime[j]) prime[j] = true;
	}
	for (int i = 2; i < max; i++) if (!prime[i])P.push_back(i);
}

int main() {
	E();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int L = 0, H = 0; int N, cnt = 0; cin >> N;
	long long int sum = 0;
	while (L < P.size() && H < P.size() && P[L] <= N) {
		if (sum >= N) sum -= P[L++];
		else if (H == N) break;
		else sum += P[H++];
		if (sum == N)cnt++;
	}
	cout << cnt;
	return 0;
}